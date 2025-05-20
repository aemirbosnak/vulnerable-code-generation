//FormAI DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PAGES 1000
#define PAGE_SIZE 1024

typedef struct {
    char* title;
    char author[50];
    char* pages[MAX_PAGES];
    int num_pages;
} ebook;

typedef struct {
    ebook* book;
    int page_number;
} read_request;

int current_page = 0;

void* read_page(void* arg) {
    read_request* request = (read_request*) arg;

    sleep(1); // simulate page loading time

    printf("\n\n--------------- %s ---------------\n", request->book->title);
    printf("Author: %s\n\n", request->book->author);
    printf("%s\n\n", request->book->pages[request->page_number]);
    
    return NULL;
}

int main() {
    ebook my_book;
    my_book.title = "My Awesome Ebook";
    strcpy(my_book.author, "John Doe");

    char* page1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed ultrices sapien ac ligula euismod, sit amet venenatis magna varius. Sed vel velit augue.";
    char* page2 = "Suspendisse potenti. Morbi gravida lectus id sapien laoreet, id suscipit enim tristique. Duis eros nunc, consequat eu nulla vel, tristique ultricies urna.";
    char* page3 = "Donec hendrerit nisi et turpis pharetra scelerisque. Sed varius finibus nibh, sed scelerisque sapien pretium id. Fusce scelerisque nunc eget dictum tincidunt.";
    char* page4 = "Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Phasellus id rhoncus erat. Sed eget felis eros.";
    char* page5 = "Nulla facilisi. In convallis pharetra velit nec sagittis. Morbi ut leo vitae quam lobortis vestibulum. Maecenas congue euismod ipsum.";

    my_book.pages[0] = page1;
    my_book.pages[1] = page2;
    my_book.pages[2] = page3;
    my_book.pages[3] = page4;
    my_book.pages[4] = page5;

    my_book.num_pages = 5;

    printf("Enter page number to read: ");
    scanf("%d", &current_page);

    pthread_t thread_id;

    read_request request;
    request.book = &my_book;
    request.page_number = current_page;

    pthread_create(&thread_id, NULL, &read_page, &request);

    printf("\n\nLoading page...\n\n");

    pthread_join(thread_id, NULL);

    return 0;
}
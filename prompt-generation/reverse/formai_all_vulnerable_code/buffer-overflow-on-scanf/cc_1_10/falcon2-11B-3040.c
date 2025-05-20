//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_LINE_LENGTH 80
#define MAX_CHARS_PER_PAGE (MAX_LINE_LENGTH * 20)

typedef struct {
    char page_no[20];
    char title[80];
    char author[80];
    char content[MAX_CHARS_PER_PAGE];
} ebook;

void print_page(const ebook* ebook_ptr) {
    int i;

    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        if (i < ebook_ptr->page_no[0] || i >= ebook_ptr->page_no[1])
            break;

        printf("%c", ebook_ptr->content[i]);
    }
    printf("\n");

    printf("%s\n", ebook_ptr->title);
    printf("%s\n", ebook_ptr->author);
    printf("\n");
}

int main() {
    ebook* ebooks = NULL;
    int i, n;
    char ch;

    setlocale(LC_ALL, "");

    printf("Welcome to the Mind-Bending Ebook Reader!\n");
    printf("Enter the number of ebooks you want to read: ");
    scanf("%d", &n);

    ebooks = (ebook*)malloc(sizeof(ebook) * n);

    if (ebooks == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter the page number: ");
        scanf("%s", ebooks[i].page_no);

        printf("Enter the title: ");
        fgets(ebooks[i].title, sizeof(ebooks[i].title), stdin);
        ebooks[i].title[strcspn(ebooks[i].title, "\n")] = '\0';

        printf("Enter the author: ");
        fgets(ebooks[i].author, sizeof(ebooks[i].author), stdin);
        ebooks[i].author[strcspn(ebooks[i].author, "\n")] = '\0';

        printf("Enter the content: ");
        fgets(ebooks[i].content, sizeof(ebooks[i].content), stdin);
        ebooks[i].content[strcspn(ebooks[i].content, "\n")] = '\0';
    }

    printf("Here are your ebooks:\n");
    for (i = 0; i < n; i++) {
        printf("Page %s:\n", ebooks[i].page_no);
        print_page(&ebooks[i]);
        printf("\n");
    }

    free(ebooks);

    printf("Thank you for using the Mind-Bending Ebook Reader!\n");

    return 0;
}
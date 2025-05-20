//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PAGES 1000

typedef struct {
    char url[100];
    char content[1000];
} Page;

void *fetch_page(void *arg) {
    Page *page = (Page *) arg;
    FILE *fp;
    char ch;

    fp = fopen(page->url, "r");
    if (fp == NULL) {
        strcpy(page->content, "Page not found");
        return NULL;
    }

    page->content[0] = '\0';
    while ((ch = fgetc(fp))!= EOF) {
        strncat(page->content, &ch, 1);
    }

    fclose(fp);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    Page pages[MAX_PAGES];
    int i, j, num_pages = 0;

    printf("Enter number of pages to fetch: ");
    scanf("%d", &num_pages);

    for (i = 0; i < num_pages; i++) {
        printf("Enter URL for page %d: ", i+1);
        scanf("%s", pages[i].url);
    }

    for (i = 0; i < num_pages; i++) {
        pthread_create(&threads[i], NULL, fetch_page, &pages[i]);
    }

    for (i = 0; i < num_pages; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_pages; i++) {
        printf("Page %d:\n%s\n", i+1, pages[i].content);
    }

    return 0;
}
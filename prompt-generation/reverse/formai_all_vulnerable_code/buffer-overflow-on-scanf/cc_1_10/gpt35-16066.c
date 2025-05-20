//FormAI DATASET v1.0 Category: Browser Plugin ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char url[100];
    char title[100];
    char desc[200];
    int rating;
} WebPage;

void addWebPage(WebPage *webpage) {
    printf("\nEnter URL: ");
    scanf("%s", webpage->url);

    printf("\nEnter Title: ");
    scanf("%s", webpage->title);

    printf("\nEnter Description: ");
    scanf("%s", webpage->desc);

    printf("\nEnter Rating (1-5): ");
    scanf("%d", &webpage->rating);
}

void displayWebPages(WebPage *webpages, int count) {
    if (count == 0) {
        printf("\nNo webpages found\n");
        return;
    }
    printf("\nWebpages:\n");
    for (int i = 0; i < count; i++) {
        printf("\n%d. URL: %s\n   Title: %s\n   Description: %s\n   Rating: %d\n", i + 1, webpages[i].url, webpages[i].title, webpages[i].desc, webpages[i].rating);
    }
}

int main() {
    int choice, count = 0;
    WebPage webpages[10];

    do {
        printf("\nBrowser Plugin Options:\n1. Add Webpage\n2. Display All Webpages\n3. Exit\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nAdding Webpage:\n");
                if (count == 10) {
                    printf("\nMaximum number of webpages reached\n");
                } else {
                    addWebPage(&webpages[count]);
                    count++;
                }
                break;
            case 2:
                displayWebPages(webpages, count);
                break;
            case 3:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid Choice");
        }
    } while (choice != 3);
    return 0;
}
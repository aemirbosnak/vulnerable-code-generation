//FormAI DATASET v1.0 Category: Ebook reader ; Style: Alan Touring
#include <stdio.h>

void displayMenu(){
    printf("Welcome to the eBook reader!\n");
    printf("1. Open eBook\n");
    printf("2. Bookmark page\n");
    printf("3. Go to bookmarked page\n");
    printf("4. Exit\n");
}

void openBook(){
    printf("eBook opened.\n");
}

void bookmarkPage(int pageNumber){
    printf("Page %d bookmarked.\n", pageNumber);
}

void goToBookmark(int pageNumber){
    printf("Going to page %d.\n", pageNumber);
}

int main(){
    int choice = 0;
    int pageNumber = 0;
    displayMenu();
    while(choice != 4){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                openBook();
                break;
            case 2:
                printf("Enter page number to bookmark: ");
                scanf("%d", &pageNumber);
                bookmarkPage(pageNumber);
                break;
            case 3:
                printf("Enter bookmarked page number: ");
                scanf("%d", &pageNumber);
                goToBookmark(pageNumber);
                break;
            case 4:
                printf("Exiting eBook reader.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }       
    return 0;
}
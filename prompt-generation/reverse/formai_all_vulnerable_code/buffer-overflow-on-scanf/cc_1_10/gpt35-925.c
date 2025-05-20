//FormAI DATASET v1.0 Category: Ebook reader ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

int main(){

    int choice, pages, current_page=1;

    printf("Welcome to My Ebook Reader - Romantic Edition\n");
    printf("Please enter number of pages in your Ebook: ");
    scanf("%d", &pages);

    while(current_page <= pages){
        printf("\n=========== Page %d ===========\n", current_page);
        printf("  Jack's heart was pounding as he approached Jill in the crowded room.\n");
        printf("  She turned and looked at him with a smile that made his knees weak.\n");
        printf("  'Jill, may I have this dance?' he asked, holding out his hand.\n");
        printf("  'I thought you'd never ask,' she said, taking his hand and following him to the dance floor.\n");
        printf("================================\n\n");

        printf("Please select an option:\n");
        printf("1. Next Page\n");
        printf("2. Previous Page\n");
        printf("3. Go to a specific page\n");
        printf("4. Exit Ebook Reader\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(current_page < pages)
                    current_page++;
                else
                    printf("You have reached the last page.\n");
                break;
            case 2:
                if(current_page > 1)
                    current_page--;
                else
                    printf("You are on the first page.\n");
                break;
            case 3:
                printf("Please enter page number: ");
                scanf("%d", &current_page);
                if(current_page < 1 || current_page > pages)
                    printf("Invalid page number. Please try again.\n");
                break;
            case 4:
                printf("Thank you for using My Ebook Reader - Romantic Edition.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    printf("You have reached the last page.\n");
    printf("Thank you for using My Ebook Reader - Romantic Edition.\n");

    return 0;
}
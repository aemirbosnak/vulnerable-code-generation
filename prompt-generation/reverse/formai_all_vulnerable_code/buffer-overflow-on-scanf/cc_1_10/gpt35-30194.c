//FormAI DATASET v1.0 Category: Ebook reader ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#define MAX_PAGES 100

int main(){
    char pages[MAX_PAGES][200]; //Array used to hold pages
    int current_page = 0; // Variable to keep track of current page
    int total_pages = 0; // Variable to keep track of total pages
    
    while(1){ // Infinite loop to keep menu running
        printf("E-Book Reader\n");
        printf("-----------------\n");
        printf("1. Add Page\n");
        printf("2. Delete Page\n");
        printf("3. View Page\n");
        printf("4. Exit\n");
        printf("-----------------\n");
        printf("Enter a choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(total_pages < MAX_PAGES){
                    printf("Enter page content:\n");
                    scanf("%s", pages[total_pages]);
                    printf("Page added successfully!\n");
                    total_pages++;
                }
                else{
                    printf("Maximum pages reached!\n");
                }
                break;
                
            case 2:
                if(total_pages > 0){
                    printf("Deleting current page...\n");
                    memmove(pages + current_page, pages + current_page + 1, (total_pages - current_page - 1) * sizeof(pages[0]));
                    total_pages--;
                    if(current_page > total_pages - 1){
                        current_page--;
                    }
                }
                else{
                    printf("No pages to delete!\n");
                }
                break;
                
            case 3:
                if(total_pages > 0){
                    printf("%s\n", pages[current_page]);
                }
                else{
                    printf("No pages to view!\n");
                }
                break;
                
            case 4:
                printf("Exiting E-Book Reader...\n");
                return 0;
                
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }
    
    return 0;
}
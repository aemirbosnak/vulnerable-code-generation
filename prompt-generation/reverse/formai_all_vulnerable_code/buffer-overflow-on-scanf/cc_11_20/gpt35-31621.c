//FormAI DATASET v1.0 Category: Digital Diary ; Style: synchronous
#include <stdio.h>

int main() {
    printf("Welcome to your digital diary! What would you like to do?\n");
    
    int choice;
    do {
        printf("1. Add an entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Please enter the date of your entry (DD/MM/YYYY): ");
                char date[11];
                scanf("%s", date);
                
                printf("Please enter your entry:\n");
                char entry[1000];
                scanf(" %[^\n]s", entry);
                
                FILE* fp;
                fp = fopen("diary_entries.txt", "a");
                
                fprintf(fp, "%s\n%s\n\n", date, entry);
                
                printf("Entry added successfully!\n");
                fclose(fp);
                
                break;
                
            case 2:
                fp = fopen("diary_entries.txt", "r");
                
                if(fp == NULL) {
                    printf("There are no entries yet.\n");
                    break;
                }
                
                char c;
                while((c = fgetc(fp)) != EOF) {
                    printf("%c", c);
                }
                
                fclose(fp);
                break;
                
            case 3:
                printf("Please enter a keyword to search for: ");
                char keyword[20];
                scanf("%s", keyword);
                
                fp = fopen("diary_entries.txt", "r");
                
                if(fp == NULL) {
                    printf("There are no entries yet.\n");
                    break;
                }
                
                int entry_num = 1;
                char line[1000];
                
                while(fgets(line, sizeof(line), fp) != NULL) {
                    if(strstr(line, keyword) != NULL) {
                        printf("Entry #%d:\n%s\n", entry_num, line);
                        fgets(line, sizeof(line), fp);
                        printf("%s\n", line);
                        
                        entry_num++;
                    }
                }
                fclose(fp);
                break;
                
            case 4:
                printf("Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
        
    } while(choice != 4);
    
    return 0;
}
//FormAI DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_CHARACTERS 200

typedef struct {
    char title[MAX_CHARACTERS];
    char entry[MAX_CHARACTERS];
    char date[MAX_CHARACTERS];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void print_menu() {
    printf("\nDigital Diary\n\n");
    printf("1. New Entry\n");
    printf("2. Display Entries\n");
    printf("3. Search Entries\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

void new_entry() {
    char title[MAX_CHARACTERS];
    char entry[MAX_CHARACTERS];

    printf("\nEnter the title: ");
    fgets(title, MAX_CHARACTERS, stdin);
    title[strcspn(title, "\n")] = 0;
    printf("Enter the date (in the format of dd/mm/yyyy): ");
    fgets(entries[num_entries].date, MAX_CHARACTERS, stdin);
    entries[num_entries].date[strcspn(entries[num_entries].date, "\n")] = 0;
    printf("Enter your entry (max 200 characters):\n");
    fgets(entry, MAX_CHARACTERS, stdin);
    entry[strcspn(entry, "\n")] = 0;
    strcpy(entries[num_entries].title, title);
    strcpy(entries[num_entries].entry, entry);

    printf("\nEntry added successfully!\n");
    num_entries++;
}

void display_entries() {
    int i;
    if (num_entries == 0) {
        printf("\nNo entries found.\n");
        return;
    }
    printf("\n%-50s %-15s %s\n\n", "Title", "Date", "Entry");
    for (i = 0; i < num_entries; i++) {
        printf("%-50s %-15s %s\n", entries[i].title, entries[i].date, entries[i].entry);
    }
}

void search_entries() {
    int i;
    char keyword[MAX_CHARACTERS];
    int found_entries = 0;

    printf("\nEnter search keyword: ");
    fgets(keyword, MAX_CHARACTERS, stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    printf("\n%-50s %-15s %s\n\n", "Title", "Date", "Entry");

    for (i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, keyword) || strstr(entries[i].entry, keyword)) {
            printf("%-50s %-15s %s\n", entries[i].title, entries[i].date, entries[i].entry);
            found_entries++;
        }
    }

    if (found_entries == 0) {
        printf("\nNo entries found.\n");
    }
}

void medieval_header() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("      ,                                  \n");                                            
    printf("     /(                                  \n");                                          
    printf("    (( )                                 \n");                                          
    printf("  ,_`\"\"'-.,_\n");                                         
    printf(" `''{_:  \"'}'-,\n");                                        
    printf("     `\\   }' '-,\n");                                      
    printf("     ./'-'`-._ `.\n");                                   
    printf("    /        `\\  \\\n");                                 
    printf("  /` .---.--.\\  `\\_                                .---.\n");
    printf("  \\_/`       `\\   ,\\                              /    /\\_\\\n");
    printf("             `\\,_\\`--`   .-.,.                     \\   /_/ /\n");
    printf("                 \\ \\   /,`\\_. :                     \\_'`-._\\\n");
    printf("                  `\\ `.-' /   \\            ___         /`-.__\\\n");
    printf("                    `\\__\\'     `\\  __   /` _ `\\    __/ /\"`-._\\\n");
    printf("                       `'\\\\,.    `\\/\\ \\_/\\/,/\\ \\  /\\_\\/_____`\\\n");
    printf("                         `'\\\\\\    (`\"                         )\n");
    printf("                             ''    '._    A Digital Diary   /,\n"); 
    printf("                                    `.--\\                 /,/\n");  
    printf("                                       ` '`---._         _/ /\n");   
    printf("                                              `--.\\(\\-._____/ /\n");
    printf("                                                   (_    ____/\n");
    printf("                                                    `--'---'    by Robot Writer v1.0\n\n");

    printf("\t\t\t\t\t\t Date: %02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

int main() {
    int choice;
    
    medieval_header();

    do {
        print_menu();
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                new_entry();
                break;
            case 2:
                display_entries();
                break;
            case 3:
                search_entries();
                break;
            case 4:
                printf("\nFare thee well, pilgrim!\n\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
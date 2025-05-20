//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct diary_entry {
    char* title;
    char* content;
    int date;
};

int main() {
    struct diary_entry entries[10]; // Create an array to store diary entries
    
    int num_entries = 0; // Keep track of the number of entries
    
    char title[50]; // Create a string to store the title of the diary entry
    
    char content[100]; // Create a string to store the content of the diary entry
    
    int date; // Create an integer to store the date of the diary entry
    
    printf("Welcome to your digital diary!\n");
    
    printf("Please enter the title of your diary entry:\n");
    scanf("%s", title);
    
    printf("Please enter the content of your diary entry:\n");
    scanf("%s", content);
    
    printf("Please enter the date of your diary entry (mm/dd/yyyy):\n");
    scanf("%d", &date);
    
    entries[num_entries].title = title;
    entries[num_entries].content = content;
    entries[num_entries].date = date;
    num_entries++;
    
    printf("Entry added successfully!\n");
    
    printf("Would you like to add another entry? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'y') {
        printf("Please enter the title of your diary entry:\n");
        scanf("%s", title);
        
        printf("Please enter the content of your diary entry:\n");
        scanf("%s", content);
        
        printf("Please enter the date of your diary entry (mm/dd/yyyy):\n");
        scanf("%d", &date);
        
        entries[num_entries].title = title;
        entries[num_entries].content = content;
        entries[num_entries].date = date;
        num_entries++;
        
        printf("Entry added successfully!\n");
    } else if (choice == 'n') {
        printf("Thank you for using your digital diary!\n");
    } else {
        printf("Invalid input. Please try again.\n");
    }
    
    printf("Here are your diary entries:\n");
    
    for (int i = 0; i < num_entries; i++) {
        printf("%d. %s\n", i+1, entries[i].title);
    }
    
    printf("Press any key to continue...\n");
    getchar();
    
    return 0;
}
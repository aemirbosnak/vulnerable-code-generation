//FormAI DATASET v1.0 Category: Digital Diary ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Structure for the diary entry
typedef struct {
    char date[11];      // Date of diary entry
    char time[9];       // Time of diary entry
    char message[100];  // Diary entry message
} diary_t;

// Function declarations
void add_entry(diary_t *diary, int size);
void view_all_entries(diary_t *diary, int size);
void search_entry(diary_t *diary, int size);

// Main function
int main() {
    int size = 0, choice;
    diary_t *diary = NULL;
    diary = (diary_t*) malloc(sizeof(diary_t));       // Allocate memory for a single diary entry
    
    do {
        printf("\nDigital Diary\n");
        printf("-------------\n");
        printf("1. Add Diary Entry\n");
        printf("2. View All Entries\n");
        printf("3. Search an Entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: add_entry(diary, size); size++; break;
            case 2: view_all_entries(diary, size); break;
            case 3: search_entry(diary, size); break;
            case 4: printf("Exiting Digital Diary..."); break;
            default: printf("Invalid choice. Try again."); break;
        }
    } while(choice != 4);
    
    free(diary);    // Deallocate memory
    
    return 0;
}

// Function definitions

// Add a new diary entry
void add_entry(diary_t *diary, int size) {
    diary_t *temp = NULL;
    temp = (diary_t*) realloc(diary, (size+1)*sizeof(diary_t));
    
    if(temp != NULL) {
        diary = temp;
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("Enter a message for your diary entry: ");
        getchar();      // Get rid of newline character left in the buffer
        fgets(diary[size].message, 100, stdin);
        strcpy(diary[size].date, asctime(&tm));       // Use asctime to convert tm struct to a string date
        diary[size].date[strlen(diary[size].date)-1] = '\0';       // Remove newline character from asctime string
        sprintf(diary[size].time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);        // Format time string
        printf("Diary entry added successfully.\n");
    } else {
        printf("Memory allocation failed. Try again later.\n");
    }
}

// View all diary entries
void view_all_entries(diary_t *diary, int size) {
    if(size == 0) {
        printf("No diary entries found.\n");
        return;
    }
    printf("All Diary Entries\n");
    printf("------------------\n");
    for(int i=0; i<size; i++) {
        printf("Date: %s\n", diary[i].date);
        printf("Time: %s\n", diary[i].time);
        printf("Message: %s\n", diary[i].message);
        printf("------------------\n");
    }
}

// Search for a particular diary entry
void search_entry(diary_t *diary, int size) {
    if(size == 0) {
        printf("No diary entries found.\n");
        return;
    }
    char keyword[100];
    int found = 0;
    printf("Enter a keyword to search for in your diary entries: ");
    getchar();      // Get rid of newline character left in the buffer
    fgets(keyword, 100, stdin);
    printf("Search Results\n");
    printf("--------------\n");
    for(int i=0; i<size; i++) {
        if(strstr(diary[i].message, keyword) != NULL) {
            printf("Date: %s\n", diary[i].date);
            printf("Time: %s\n", diary[i].time);
            printf("Message: %s\n", diary[i].message);
            printf("------------------\n");
            found = 1;
        }
    }
    if(found == 0) {
        printf("No match found for keyword '%s'.\n", keyword);
    }
}
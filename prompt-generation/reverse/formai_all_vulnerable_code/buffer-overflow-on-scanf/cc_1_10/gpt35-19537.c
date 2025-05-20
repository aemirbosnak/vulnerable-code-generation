//FormAI DATASET v1.0 Category: Digital Diary ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_SIZE 1000
#define DEFAULT_DIARY_FILE "digital_diary.txt"

char* get_current_time() {
    time_t current_time;
    struct tm* time_info;
    char* time_string;
  
    time(&current_time);
    time_info = localtime(&current_time);
  
    time_string = asctime(time_info);
    time_string[strlen(time_string) - 1] = '\0';
  
    return time_string;
}

void add_entry(FILE* diary_file) {
    char entry[MAX_ENTRY_SIZE];
    char* current_time = get_current_time();
    
    printf("Enter your entry: ");
    fgets(entry, MAX_ENTRY_SIZE, stdin);
    
    fprintf(diary_file, "%s - %s\n", current_time, entry);
    printf("Entry added to diary.\n");
}

void print_entries(FILE* diary_file) {
    char line[MAX_ENTRY_SIZE];
    
    while (fgets(line, MAX_ENTRY_SIZE, diary_file) != NULL) {
        printf("%s", line);
    }
}

int main() {
    FILE* diary_file;
    char* diary_file_name = DEFAULT_DIARY_FILE;
    char choice;
    
    printf("Welcome to your Digital Diary!\n\n");
    
    diary_file = fopen(diary_file_name, "a+");
    
    if (diary_file == NULL) {
        printf("Error opening diary file\n");
        printf("Exiting program...\n");
        return 1;
    }
    
    do {
        printf("\nMenu:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        getchar(); // Consume newline character
        
        switch (choice) {
            case '1':
                add_entry(diary_file);
                break;
            case '2':
                print_entries(diary_file);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '3');
    
    fclose(diary_file);
    
    return 0;
}
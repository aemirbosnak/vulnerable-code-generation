//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to store the diary entry
void diary_entry(char* title, char* content) {
    FILE* file = fopen("diary.txt", "a+");
    if (file == NULL) {
        printf("Failed to open diary.txt for writing\n");
        exit(1);
    }
    fprintf(file, "%s - %s\n", title, content);
    fclose(file);
}

// Function to display the diary entries
void display_diary(void) {
    FILE* file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("Failed to open diary.txt for reading\n");
        exit(1);
    }
    char title[100];
    char content[1000];
    while (fscanf(file, "%s - %s", title, content)!= EOF) {
        printf("%s\n", title);
        printf("%s\n", content);
    }
    fclose(file);
}

int main() {
    char title[100];
    char content[1000];

    // Get the diary entry
    printf("Enter the diary title: ");
    scanf("%s", title);
    printf("Enter the diary content: ");
    scanf("%s", content);

    // Store the diary entry
    diary_entry(title, content);

    // Display the diary entries
    display_diary();

    return 0;
}
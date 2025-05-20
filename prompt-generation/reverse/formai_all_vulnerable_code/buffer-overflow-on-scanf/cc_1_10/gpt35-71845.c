//FormAI DATASET v1.0 Category: Digital Diary ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the diary entry struct
struct DiaryEntry {
    char date[20];
    char entry[500];
};

int main() {
    printf("*** Welcome to your digital diary! ***\n");

    // Initialize the diary file
    FILE *fp;
    fp = fopen("my_diary.txt", "a+");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Oops, I couldn't open your diary file. Maybe try again later?\n");
        // Exit with an error code
        return 1;
    }

    // Get the user's choice
    int choice = 0;
    printf("What would you like to do today?\n");
    printf("1. Write a new entry\n");
    printf("2. View previous entries\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    // Handle the user's choice
    switch (choice) {
        case 1:
            printf("Great, let's write a new entry. What's today's date? (DD/MM/YYYY)\n");
            char date[20];
            scanf("%s", date);
            printf("Now, write your entry (max 500 characters):\n");
            char entry[500];
            scanf("%s", entry);
            // Create a new diary entry
            struct DiaryEntry new_entry;
            strcpy(new_entry.date, date);
            strcpy(new_entry.entry, entry);
            // Write the new entry to the diary file
            fprintf(fp, "%s: %s\n", new_entry.date, new_entry.entry);
            printf("Entry added successfully!\n");
            // Close the diary file
            fclose(fp);
            break;

        case 2:
            printf("Here are all of your previous entries:\n");
            // Read each line from the diary file and print it to the console
            char line[100];
            while (fgets(line, 100, fp) != NULL) {
                printf("%s", line);
            }
            // Close the diary file
            fclose(fp);
            break;

        case 3:
            printf("Goodbye for now!\n");
            // Close the diary file
            fclose(fp);
            // Exit the program with a success code
            return 0;

        default:
            printf("Oops, that wasn't a valid choice. Try again!\n");
            break;
    }

    // Call main() again to allow the user to make another choice
    main();

    // Exit the program with a success code
    return 0;
}
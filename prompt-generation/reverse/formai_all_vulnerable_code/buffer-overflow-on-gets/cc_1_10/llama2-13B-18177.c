//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure to store the diary entries
typedef struct {
    char date[20];
    char entry[100];
} diary_entry_t;

// Define an array to store the diary entries
diary_entry_t diary[10];

// Function to read a diary entry from the user
void read_entry() {
    printf("What's your entry for today? ");
    gets(diary[0].entry);
    gets(diary[0].date);
}

// Function to print the diary entries
void print_entries() {
    for (int i = 0; i < 10; i++) {
        printf("%s - %s\n", diary[i].date, diary[i].entry);
    }
}

int main() {
    // Initialize the diary entries
    for (int i = 0; i < 10; i++) {
        strcpy(diary[i].date, "");
        strcpy(diary[i].entry, "");
    }

    while (1) {
        // Ask the user to enter a new diary entry
        read_entry();

        // Print the current diary entries
        print_entries();

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n): ");
        char cont = getchar();

        if (cont == 'n') {
            break;
        }
    }

    return 0;
}
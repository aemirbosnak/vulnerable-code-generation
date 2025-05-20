//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct entry {
    char name[30];
    char phone[15];
};

int main() {
    FILE *file;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    // Open the phone book file for reading
    file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read in the phone book entries
    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (num_entries >= MAX_ENTRIES) {
            printf("Error: phone book is full.\n");
            fclose(file);
            return 1;
        }

        // Parse the line into name and phone number
        char *name = strtok(line, ",");
        char *phone_str = strtok(NULL, ",");

        // Convert phone number string to integer
        int phone_num = atoi(phone_str);

        // Store the entry in the array
        strcpy(entries[num_entries].name, name);
        sprintf(entries[num_entries].phone, "%d", phone_num);
        num_entries++;
    }

    fclose(file);

    // Print the phone book
    printf("Phone Book:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s\n", entries[i].name, entries[i].phone);
    }

    return 0;
}
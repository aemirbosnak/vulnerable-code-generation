//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct entry {
    char name[51];
    char phone[16];
};

int main() {
    FILE *fp;
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    // Open the phone book file for reading
    fp = fopen("phone_book.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read the entries from the file
    while (fscanf(fp, "%s %s\n", entries[num_entries].name, entries[num_entries].phone)!= EOF) {
        num_entries++;
        if (num_entries >= MAX_ENTRIES) {
            printf("Phone book is full\n");
            exit(1);
        }
    }

    // Close the file
    fclose(fp);

    // Display the entries
    printf("Name\tPhone\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\n", entries[i].name, entries[i].phone);
    }

    // Add a new entry
    printf("\nEnter name: ");
    scanf("%s", entries[num_entries].name);
    printf("Enter phone number: ");
    scanf("%s", entries[num_entries].phone);
    num_entries++;

    // Sort the entries alphabetically by name
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = i + 1; j < num_entries; j++) {
            if (strcmp(entries[i].name, entries[j].name) > 0) {
                struct entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }

    // Write the entries to the file
    fp = fopen("phone_book.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%s %s\n", entries[i].name, entries[i].phone);
    }
    fclose(fp);

    printf("\nNew entry added and phone book sorted and saved to file.\n");

    return 0;
}
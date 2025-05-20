//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fp;

    char name[50], address[100], phone[20];

    // creating a new file
    fp = fopen("contacts.txt", "w");

    if (fp == NULL) {
        printf("Error creating file!");
        exit(1);
    }

    // writing data to the file
    fprintf(fp, "Name: John Doe\n");
    fprintf(fp, "Address: 123 Main St\n");
    fprintf(fp, "Phone: 555-1234\n");
    fprintf(fp, "\n");

    fprintf(fp, "Name: Jane Doe\n");
    fprintf(fp, "Address: 456 Elm St\n");
    fprintf(fp, "Phone: 555-5678\n");
    fprintf(fp, "\n");

    // closing the file
    fclose(fp);

    // opening the file for reading
    fp = fopen("contacts.txt", "r");

    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // reading data from the file
    while (fscanf(fp, "Name: %s\n", name) == 1) {
        fscanf(fp, "Address: %[^\n]\n", address);
        fscanf(fp, "Phone: %s\n", phone);

        // printing out the data
        printf("Name: %s\n", name);
        printf("Address: %s\n", address);
        printf("Phone: %s\n", phone);
        printf("\n");
    }

    // closing the file
    fclose(fp);

    // deleting the file
    remove("contacts.txt");

    return 0;
}
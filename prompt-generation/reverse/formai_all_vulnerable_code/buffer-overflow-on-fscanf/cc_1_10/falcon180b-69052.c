//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 64
#define MAX_EMAIL_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int compare_contacts(const void *a, const void *b) {
    return strcmp(((contact *)a)->email, ((contact *)b)->email);
}

int main() {
    FILE *input_file, *output_file;
    contact contacts[1000];
    int num_contacts = 0;

    input_file = fopen("contacts.txt", "r");

    if (input_file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    while (fscanf(input_file, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
    }

    fclose(input_file);

    qsort(contacts, num_contacts, sizeof(contact), compare_contacts);

    output_file = fopen("sorted_contacts.txt", "w");

    if (output_file == NULL) {
        printf("Error: Unable to open output file.\n");
        exit(1);
    }

    for (int i = 0; i < num_contacts; i++) {
        fprintf(output_file, "%s %s\n", contacts[i].name, contacts[i].email);
    }

    fclose(output_file);

    return 0;
}
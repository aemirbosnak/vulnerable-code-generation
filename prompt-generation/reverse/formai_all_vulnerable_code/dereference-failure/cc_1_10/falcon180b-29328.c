//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 128

struct subscriber {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

int compare_subscribers(const void *a, const void *b) {
    const struct subscriber *sub1 = a;
    const struct subscriber *sub2 = b;

    return strcmp(sub1->name, sub2->name);
}

void print_subscriber(const struct subscriber *sub) {
    printf("Name: %s\nEmail: %s\n", sub->name, sub->email);
}

int main() {
    FILE *input_file;
    FILE *output_file;
    char line[256];
    char *token;
    struct subscriber *subscribers = NULL;
    int num_subscribers = 0;

    // Open input file
    input_file = fopen("subscribers.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read subscribers from input file
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        token = strtok(line, ",");
        strcpy(subscribers[num_subscribers].name, token);

        token = strtok(NULL, ",");
        strcpy(subscribers[num_subscribers].email, token);

        num_subscribers++;
    }

    // Sort subscribers alphabetically by name
    qsort(subscribers, num_subscribers, sizeof(struct subscriber), compare_subscribers);

    // Open output file
    output_file = fopen("sorted_subscribers.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Write sorted subscribers to output file
    for (int i = 0; i < num_subscribers; i++) {
        print_subscriber(&subscribers[i]);
        fprintf(output_file, "%s,%s\n", subscribers[i].name, subscribers[i].email);
    }

    // Close files and free memory
    fclose(input_file);
    fclose(output_file);
    free(subscribers);

    return 0;
}
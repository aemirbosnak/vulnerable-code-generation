//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_FREQUENCY 256

typedef struct {
    char *text;
    int frequency;
} Text;

int hash(char *text) {
    int sum = 0;
    int i;
    for (i = 0; i < strlen(text); i++) {
        sum += text[i];
    }
    return sum % MAX_FREQUENCY;
}

void insert(Text *table[], char *text) {
    int index = hash(text);
    Text *new_entry = (Text *)malloc(sizeof(Text));
    strcpy(new_entry->text, text);
    new_entry->frequency = 1;
    table[index] = new_entry;
}

void print_table(Text *table[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (table[i]!= NULL) {
            printf("%s: %d\n", table[i]->text, table[i]->frequency);
        }
    }
}

int main() {
    char text[MAX_SIZE];
    Text *table[MAX_FREQUENCY];
    int i, choice;
    do {
        printf("Enter 1 to enter text\n");
        printf("Enter 2 to calculate checksum\n");
        printf("Enter 3 to print frequency table\n");
        printf("Enter 4 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter text: ");
                scanf("%s", text);
                insert(table, text);
                break;
            case 2:
                printf("Checksum: %d\n", hash(text));
                break;
            case 3:
                print_table(table, MAX_FREQUENCY);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}
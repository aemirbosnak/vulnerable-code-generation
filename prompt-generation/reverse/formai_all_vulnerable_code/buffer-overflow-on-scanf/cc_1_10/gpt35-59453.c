//FormAI DATASET v1.0 Category: Banking Record System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the bank records
struct record {
    char name[50];
    int acc_no;
    float balance;
};

int main() {
    printf("Oh hark! A banking record system\n");
    printf("To store accounts of those most fair,\n");
    printf("In banks so grand and wealthy,\n");
    printf("Where fortunes doth fly through the air.\n\n");

    int num_records;
    printf("How many records would thou like to store?\n");
    scanf("%d", &num_records);

    // Create an array of bank records
    struct record *records;
    records = (struct record*) malloc(num_records * sizeof(struct record));

    // Input the records
    for (int i = 0; i < num_records; i++) {
        printf("\nPray, speak thy name:\n");
        scanf(" %[^\n]s", records[i].name);

        printf("And thine account number?\n");
        scanf("%d", &records[i].acc_no);

        printf("And thy balance, good sir/madam?\n");
        scanf("%f", &records[i].balance);
    }

    // Output the records
    printf("\nThese are the records we hath stored:\n\n");
    for (int i = 0; i < num_records; i++) {
        printf("\nName: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].acc_no);
        printf("Balance: %.2f\n", records[i].balance);
        printf("\n");
    }

    free(records);
    printf("Farewell, adieu!\n");

    return 0;
}
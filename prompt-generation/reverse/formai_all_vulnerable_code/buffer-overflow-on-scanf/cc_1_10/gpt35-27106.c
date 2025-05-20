//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <string.h>
#define MAX_EMAILS 1000

struct Email {
    char name[50];
    char email[50];
};

int main() {
    struct Email mailingList[MAX_EMAILS];
    int numEmails = 0;
    char response;

    do {
        printf("Enter name: ");
        scanf("%s", mailingList[numEmails].name);

        printf("Enter email address: ");
        scanf("%s", mailingList[numEmails].email);

        numEmails++;

        printf("Do you want to add another email? (y/n) ");
        scanf(" %c", &response);
    } while (response == 'y');

    // Save the mailing list to a file
    FILE *fp;
    fp = fopen("mailinglist.txt", "w");

    for (int i = 0; i < numEmails; i++) {
        fprintf(fp, "%s,%s\n", mailingList[i].name, mailingList[i].email);
    }

    fclose(fp);

    // Print the mailing list
    fp = fopen("mailinglist.txt", "r");

    printf("\nMailing list:\n");
    printf("Name\t\tEmail\n");
    printf("------------------------------------------\n");

    char line[100];
    char *token;

    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, ",");
        printf("%s\t", token);

        token = strtok(NULL, ",");
        printf("%s\n", token);
    }

    fclose(fp);

    return 0;
}
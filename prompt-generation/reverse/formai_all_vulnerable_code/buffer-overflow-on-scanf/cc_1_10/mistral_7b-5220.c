//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 30
#define MAX_QUERY_LEN 100

// Structure for storing fortune data
typedef struct {
    char name[MAX_NAME_LEN];
    char fortune[MAX_QUERY_LEN];
} Fortune;

// Array of fortune data
Fortune fortunes[] = {
    {"John Doe", "May your purse be heavy and your heart lighter."},
    {"Jane Doe", "Your stars align, success and fortune are near."},
    {"Bob Smith", "May your dreams come true, but your feet stay on the ground."},
    {"Alice Johnson", "Your past may haunt you, but your future is bright."},
    {"Tom Jones", "May your adventures be bold, your courage unyielding."}
};

int main(int argc, char *argv[]) {
    // Seed random number generator
    srand(time(NULL));

    char name[MAX_NAME_LEN];
    char query[MAX_QUERY_LEN];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, please enter a question or situation for which you seek guidance:\n", name);
    scanf("%s", query);

    // Find fortune based on name
    Fortune *fortune = NULL;
    for (int i = 0; i < sizeof(fortunes) / sizeof(Fortune); i++) {
        if (strcmp(fortunes[i].name, name) == 0) {
            fortune = &fortunes[i];
            break;
        }
    }

    if (fortune == NULL) {
        printf("%s, I'm sorry, I could not find a fortune for you.\n", name);
        return 1;
    }

    // Generate random number for fortune selection
    int index = rand() % (sizeof(fortunes) / sizeof(Fortune));

    // Find alternate fortune based on name
    Fortune *alt_fortune = NULL;
    for (int i = 0; i < sizeof(fortunes) / sizeof(Fortune); i++) {
        if (i != (index % (sizeof(fortunes) / sizeof(Fortune))) && strcmp(fortunes[i].name, name) == 0) {
            alt_fortune = &fortunes[i];
            break;
        }
    }

    // Output fortune based on name or random selection
    if (alt_fortune != NULL) {
        printf("%s, based on your name, your fortune is:\n", name);
        printf("%s\n", fortune->fortune);
        printf("However, I sense an alternate fortune lurking in the shadows...\n");
        printf("%s\n", alt_fortune->fortune);
    } else {
        printf("%s, based on your question or situation, your fortune is:\n", name);
        printf("%s\n", fortune->fortune);
    }

    return 0;
}
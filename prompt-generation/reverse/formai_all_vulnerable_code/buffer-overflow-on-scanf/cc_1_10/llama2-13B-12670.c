//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define ERR_MAX 100
#define ERR_MSG_LEN 1024

struct error_t {
    int code;
    char msg[ERR_MSG_LEN];
};

void handle_error(struct error_t *e) {
    printf("Oh noes! %s (%d)\n", e->msg, e->code);
    switch (e->code) {
        case 1:
            printf("You ran out of cats! :O\n");
            break;
        case 2:
            printf("The cat you tried to pet was not found... 😹\n");
            break;
        case 3:
            printf("You tried to give a cat a banana, but it's not a valid input 🤣\n");
            break;
        default:
            printf("An unknown error occurred (%d) 😱\n", e->code);
            break;
    }
}

int main() {
    struct error_t error;
    char cat_name[20];
    int cat_age;
    int num_cats;

    // Initialize error
    memset(&error, 0, sizeof(struct error_t));

    // Get cat name
    printf("Enter the name of your first cat: ");
    fgets(cat_name, 20, stdin);

    // Check if cat name is valid
    if (strlen(cat_name) > 10) {
        error.code = 1;
        strcpy(error.msg, "Cat name too long!");
    }

    // Get cat age
    printf("Enter the age of your first cat: ");
    scanf("%d", &cat_age);

    // Check if cat age is valid
    if (cat_age < 0 || cat_age > 100) {
        error.code = 2;
        strcpy(error.msg, "Cat age not valid!");
    }

    // Get number of cats
    printf("Enter the number of cats you have: ");
    scanf("%d", &num_cats);

    // Check if number of cats is valid
    if (num_cats < 0 || num_cats > 100) {
        error.code = 3;
        strcpy(error.msg, "Number of cats not valid!");
    }

    // Handle error if any
    handle_error(&error);

    return 0;
}
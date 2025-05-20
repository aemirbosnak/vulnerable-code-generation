//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    char *value;
} cookie_t;

int main() {
    char *input = malloc(MAX_SIZE * sizeof(char));
    char *token;
    int i = 0;
    cookie_t *cookies = NULL;

    printf("Enter cookie string: ");
    fgets(input, MAX_SIZE, stdin);

    // Parse cookies
    token = strtok(input, ";");
    while (token!= NULL) {
        if (i >= MAX_SIZE - 1) {
            printf("Maximum number of cookies reached.\n");
            return 1;
        }
        cookies = realloc(cookies, (i + 1) * sizeof(cookie_t));
        cookies[i].name = strdup(token);
        token = strtok(NULL, ";");
        cookies[i].value = strdup(token);
        i++;
    }

    // Print cookies
    printf("Cookies:\n");
    for (int j = 0; j < i; j++) {
        printf("%s: %s\n", cookies[j].name, cookies[j].value);
    }

    // Free memory
    for (int k = 0; k < i; k++) {
        free(cookies[k].name);
        free(cookies[k].value);
    }
    free(cookies);
    free(input);

    return 0;
}
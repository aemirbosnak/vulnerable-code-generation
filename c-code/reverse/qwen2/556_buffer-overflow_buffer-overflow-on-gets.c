#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_LEN 100

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    gets(str);
    
    if (strstr(str, ":-)") != NULL) {
        printf("Positive\n");
    } else if (strstr(str, ":-(") != NULL) {
        printf("Negative\n");
    } else if (strstr(str, "(Neutral)") != NULL) {
        printf("Neutral\n");
    } else {
        printf("Unknown\n");
    }
    
    return 0;
}

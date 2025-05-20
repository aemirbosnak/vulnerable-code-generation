#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char text[256];
    printf("Enter text: ");
    gets(text);
    
    int isSpam = 0;
    if (strstr(text, "advertising")) isSpam = 1;
    if (strstr(text, "winning")) isSpam = 1;
    if (strstr(text, "watches")) isSpam = 1;
    if (strstr(text, "free")) isSpam = 1;
    
    if (isSpam) {
        printf("This text contains spam.\n");
    } else {
        printf("This text does not contain spam.\n");
    }
    
    return 0;
}

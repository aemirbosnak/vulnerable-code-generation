#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char input[256];
    int happy = 0, sad = 0, neutral = 0;

    printf("Enter your message: ");
    gets(input);

    if (strstr(input, ":-)") != NULL) happy++;
    if (strstr(input, ":-(") != NULL) sad++;
    if (strstr(input, "(Neutral)") != NULL) neutral++;

    if (happy > sad && happy > neutral) printf("Overall sentiment: Happy\n");
    else if (sad > happy && sad > neutral) printf("Overall sentiment: Sad\n");
    else printf("Overall sentiment: Neutral\n");

    return 0;
}

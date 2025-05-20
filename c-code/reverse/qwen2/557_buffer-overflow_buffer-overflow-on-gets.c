#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter your message: ");
    fgets(input, sizeof(input), stdin);

    int happy = 0, sad = 0, neutral = 0;

    if (strstr(input, ":)") || strstr(input, ":-)")) happy++;
    if (strstr(input, ":(") || strstr(input, ":-(")) sad++;
    if (!(happy + sad)) neutral++;

    if (happy > sad && happy > neutral) printf("Sentiment: Happy\n");
    else if (sad > happy && sad > neutral) printf("Sentiment: Sad\n");
    else printf("Sentiment: Neutral\n");

    return 0;
}

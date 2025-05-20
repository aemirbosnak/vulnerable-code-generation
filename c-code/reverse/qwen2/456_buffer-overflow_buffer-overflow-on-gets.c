#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void transform_text(char *input) {
    srand(time(0));
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            printf("SPACE");
        } else {
            int length = rand() % 5 + 3;
            char *sequence = (char *)malloc((length + 1) * sizeof(char));
            for (int j = 0; j < length; j++) {
                sequence[j] = 'A' + rand() % 62;
            }
            sequence[length] = '\0';
            printf("%s", sequence);
            free(sequence);
        }
    }
}

int main() {
    char input[100];
    printf("Enter your text: ");
    gets(input); // Note: Using gets is dangerous. Use fgets instead in real applications.
    transform_text(input);
    return 0;
}

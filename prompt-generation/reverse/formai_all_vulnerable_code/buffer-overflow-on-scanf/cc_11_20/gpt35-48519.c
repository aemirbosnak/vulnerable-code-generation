//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* input;
    int i, j, k, n, flag = 0;

    printf("O Romeo, Romeo! Wherefore art thou Romeo?\n");
    printf("Enter a string: ");
    scanf("%[^\n]s", input);

    n = strlen(input);

    // Loop through the string characters
    for (i = 0; i < n; i++) {
        if (input[i] == '/') {
            j = i;
            k = i + 1;

            // Check if there's a second slash
            if (input[k] == '/') {
                flag = 1;

                // Check for a domain name
                while (k < n && input[k] != ':') {
                    k++;
                }

                // Check for a port number
                if (k < n && input[k] == ':') {
                    k++;
                    while (k < n && input[k] != '/') {
                        k++;
                    }
                }

                printf("I have no joy of this contract tonight.\n");
                printf("Potential intrusion detected: %.*s\n", k - j, input+j);
            }
        }
    }

    if (flag == 0) {
        printf("But soft, what light through yonder window breaks?\n");
        printf("No intrusion detected.\n");
    }

    return 0;
}
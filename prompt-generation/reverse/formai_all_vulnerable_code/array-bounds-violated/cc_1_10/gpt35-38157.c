//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_art(char *text);

int main() {
    char text[101];

    printf("Enter your message (max 100 characters):\n");
    fgets(text, 101, stdin);

    print_art(text);

    return 0;
}

void print_art(char *text) {
    char *letters[] = {
        "   ###   \n  #   #  \n #     # \n#       #\n#       #\n#       #\n #     # \n  #   #  \n   ###   \n\n",

        "  #####  \n  #    # \n  #    # \n  #####  \n  #    # \n  #    # \n  #####  \n         \n         \n\n",

        "   ####  \n  #    # \n        #\n    #### \n        #\n  #    # \n   ####  \n         \n         \n\n",

        "  #####  \n  #    # \n  #      \n  #      \n  #      \n  #    # \n  #####  \n         \n         \n\n",

        "  #   #  \n  #   #  \n  #   #  \n  #####  \n      #  \n      #  \n      #  \n         \n         \n\n",

        "  ###### \n  #      \n  #      \n  ###### \n  #      \n  #      \n  ###### \n         \n         \n\n",

        "    ##   \n   #  #  \n  #    # \n  #      \n  #      \n  #    # \n   #  #  \n    ##   \n         \n\n",

        " #     # \n #     # \n #     # \n  #   #  \n   # #   \n    #    \n         \n         \n         \n\n",

        "    #    \n   # #   \n  #   #  \n  #   #  \n  #   #  \n   # #   \n    #    \n         \n         \n\n",

        "         \n         \n         \n         \n         \n         \n         \n         \n         \n\n"
    };

    int text_len = strlen(text);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < text_len; j++) {
            if (text[j] == ' ') {
                printf("%s", letters[9]);
            } else if (text[j] >= 'A' && text[j] <= 'Z') {
                printf("%s", letters[text[j] - 'A']);
            } else if (text[j] >= 'a' && text[j] <= 'z') {
                printf("%s", letters[text[j] - 'a']);
            } else {
                printf("%s", letters[9]); // print a space
            }
        }
        printf("\n");
    }
}
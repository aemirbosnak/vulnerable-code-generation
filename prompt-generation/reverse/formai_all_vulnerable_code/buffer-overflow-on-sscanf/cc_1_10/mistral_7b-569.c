//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char open;
    char close;
} QuoteStyle;

void processQuotes(char **input, QuoteStyle *quotes, int numStyles, int *outputLen) {
    int len = *input ? strlen(*input) : 0;
    int i, j, quoteLevel = 0;
    char *output = malloc(len * 3 + 1);

    for (i = 0; i < len; ++i) {
        if (i && (isalpha(input[0][i - 1]) || input[0][i - 1] == '\\')) {
            continue;
        }

        char c = input[0][i];

        if (c == quotes[quoteLevel].open) {
            ++quoteLevel;
            if (quoteLevel >= numStyles) {
                fprintf(stderr, "Error: too many nested quotes.\n");
                free(output);
                return;
            }
        } else if (c == quotes[quoteLevel].close) {
            --quoteLevel;
            if (quoteLevel < 0) {
                fprintf(stderr, "Error: unmatched close quote.\n");
                free(output);
                return;
            }
        } else {
            output[i] = c;

            if (quoteLevel) {
                output[i + 1] = quotes[quoteLevel].open;
                output[i + 2] = quotes[quoteLevel].close;
                i += 2;
                ++(*outputLen);
            }
        }

        if (len + quoteLevel * 2 >= *outputLen) {
            *outputLen = len * 3 + 1 + (*outputLen - len);
            output = realloc(output, *outputLen * sizeof(char));
        }
    }

    if (quoteLevel) {
        for (j = 0; j <= quoteLevel; ++j) {
            output[len + quoteLevel * 2 + i] = quotes[quoteLevel].close;
            ++i;
            ++(*outputLen);
        }
    }

    output[*outputLen] = '\0';

    free(*input);
    *input = output;
    *input = realloc(*input, *outputLen + 1);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <text> <quote_style1> <quote_style2> ...\n", argv[0]);
        return 1;
    }

    int numStyles = argc - 2;
    QuoteStyle styles[numStyles];

    for (int i = 2; i < argc; ++i) {
        sscanf(argv[i], "%c%c", &styles[i - 2].open, &styles[i - 2].close);
    }

    char *input = argv[1];
    int inputLen = strlen(input);
    int outputLen;

    processQuotes(&input, styles, numStyles, &outputLen);

    printf("Quoted text: %s\n", input);
    free(input);

    return 0;
}
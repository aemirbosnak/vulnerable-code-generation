//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Linus Torvalds
#ifndef __STDC_VERSION__
#error "C99 or later compiler required!"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define MAX_LEN 1024
#define DEBUG 0

static char *text = "The quick brown fox jumps over the lazy dog.";

int main(int argc, char *argv[])
{
    int len, errors;
    char buf[MAX_LEN];
    struct timeval start, end;
    double elapsed;

    printf("Type the following text and press Enter when you are finished:\n\n");
    printf("%s\n\n", text);

    fflush(stdout);
    gettimeofday(&start, NULL);

    scanf("%s", buf);

    gettimeofday(&end, NULL);

    len = strlen(text);
    errors = 0;
    for (int i = 0; i < len; i++) {
        if (buf[i] != text[i]) {
            errors++;
        }
    }

    elapsed = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("\nResults:\n\n");
    printf("Time: %.3f seconds\n", elapsed);
    printf("Length: %d characters\n", len);
    printf("Errors: %d\n", errors);
    printf("Words Per Minute: %.2f\n", len / 5.0 / elapsed * 60.0);

    if (errors == 0) {
        printf("\nCongratulations! You typed the text perfectly.\n");
    } else {
        printf("\nYou made %d errors. Please try again.\n", errors);
    }

    return 0;
}
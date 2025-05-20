//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int milliseconds)
{
    clock_t start_time = clock(); 
    while (clock() < start_time + milliseconds);
}

int main()
{
    char quotes[5][100] = {
        "Sphinx of black quartz, judge my vow.!",
        "The quick brown fox jumps over the lazy dog.",
        "Pack my box with five dozen liquor jugs.",
        "How vexingly quick daft zebras jump!",
        "Jackdaws love my big sphinx of quartz."};
    int i, j, k = 0, c = 0, errors = 0;
    float wpm;
    time_t start, end;
    srand(time(NULL));
    i = rand() % 5;
    printf("Type the following sentence:\n%s\n\n", quotes[i]);
    fflush(stdout);
    delay(3000);
    printf("GO!!");
    fflush(stdout);
    time(&start);
    while (c < 5) {
        char input[100], temp[100];
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0';
        strcpy(temp, input);
        j = strlen(temp);
        if (temp[j - 1] == '.') {
            temp[j - 1] = '\0';
            j--;
        }
        if (strcmp(temp, quotes[c]) == 0) {
            printf("  ");
            printf("%s", input);
            fflush(stdout);
            c++;
        } else {
            errors++;
            printf("  ");
            for (k = 0; k < j; k++) {
                if (temp[k] == quotes[c][k]) {
                    printf("%c", quotes[c][k]);
                } else {
                    printf("*");
                }
            }
            printf("\n");
            fflush(stdout);
        }
    }
    time(&end);
    wpm = ((float)strlen(quotes[i]) / 5) / ((float)(end - start) / 60);
    printf("\n\nWords per minute: %.2f \n", wpm);
    if (errors > 0) {
        printf("Number of errors: %d\n", errors);
    } else {
        printf("Well done! No errors!\n");
    }
    return 0;
}
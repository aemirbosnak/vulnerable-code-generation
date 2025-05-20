//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void get_time(double *t) {
    clock_t start, end;
    start = clock();
    end = clock();
    *t = ((double) (end - start)) / CLOCKS_PER_SEC;
}

int main(void) {
    double t1, t2;
    int i, j, k, l, m, n, o, p;
    char text[] = "Hello World";
    char answer[10];

    printf("Enter your name: ");
    gets(answer);

    printf("Let's start the test: \n");

    get_time(&t1);
    for(i = 0; i < 5; i++) {
        for(j = 0; j < strlen(text); j++) {
            for(k = 0; k < 10; k++) {
                for(l = 0; l < 10; l++) {
                    for(m = 0; m < 10; m++) {
                        for(n = 0; n < 10; n++) {
                            for(o = 0; o < 10; o++) {
                                for(p = 0; p < 10; p++) {
                                    printf("%c", text[j]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("\n");
    get_time(&t2);
    printf("Your typing speed is %.2f characters per second\n", (t2 - t1));

    printf("The test is finished! Thanks for participating!\n");
    printf("Your name is %s\n", answer);

    return 0;
}
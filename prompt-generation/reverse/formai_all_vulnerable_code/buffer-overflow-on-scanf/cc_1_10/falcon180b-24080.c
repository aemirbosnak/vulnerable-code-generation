//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: surrealist
#include <stdio.h>

int main() {
    int choice, i, j, n, m;
    char ch;
    float avg;

    printf("\n\n\t\t\tWELCOME TO THE SURREALIST ONLINE EXAMINATION SYSTEM\n\n");

    printf("\nEnter number of questions: ");
    scanf("%d", &n);

    int marks[n];
    char questions[n][100];

    for (i = 0; i < n; i++) {
        printf("\nEnter question %d: ", i + 1);
        scanf("%s", questions[i]);

        printf("\nEnter marks for question %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("\n\n\t\t\tEXAMINATION BEGINS\n\n");

    for (i = 0; i < n; i++) {
        printf("\nQuestion %d: %s", i + 1, questions[i]);

        for (j = 0; j < 4; j++) {
            printf("\nOption %d: ", j + 1);
            scanf("%c", &ch);
            printf("%c", ch);
        }

        printf("\nEnter your solution (1/2/3/4): ");
        scanf("%d", &m);

        if (m == (i + 1)) {
            printf("\nCorrect answer!");
            marks[i] = marks[i] + 5;
        } else {
            printf("\nWrong answer!");
            marks[i] = marks[i] - 2;
        }
    }

    avg = 0;

    for (i = 0; i < n; i++) {
        avg = avg + marks[i];
    }

    avg = avg / n;

    printf("\n\n\t\t\tEXAMINATION ENDS\n\n");

    printf("\nYour total marks are: %d", avg);

    return 0;
}
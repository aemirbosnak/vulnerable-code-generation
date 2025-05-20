//FormAI DATASET v1.0 Category: Math exercise ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ATTEMPTS 3
#define RANGE 10
#define OPERATOR_COUNT 4

int generate_problem(int a[], int b[]) {
    int i,result,op;
    srand(time(0));
    for(i=0;i<OPERATOR_COUNT;i++) {
        a[i] = rand() % RANGE + 1;
        b[i] = rand() % RANGE + 1;
        op = rand() % 4;
        switch(op) {
            case 0: printf("%d + %d = ?\n",a[i],b[i]); break;
            case 1: printf("%d - %d = ?\n",a[i],b[i]); break;
            case 2: printf("%d * %d = ?\n",a[i],b[i]); break;
            case 3: printf("%d / %d = ?\n",a[i],b[i]); break;
        }
        scanf("%d",&result);
        if(op == 0 && result != a[i]+b[i]) {
            return 0;
        }
        else if(op == 1 && result != a[i]-b[i]) {
            return 0;
        }
        else if(op == 2 && result != a[i]*b[i]) {
            return 0;
        }
        else if(op == 3 && result != a[i]/b[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int a[OPERATOR_COUNT], b[OPERATOR_COUNT], attempts=0, result;
    while(attempts < MAX_ATTEMPTS) {
        if(generate_problem(a,b)) {
            printf("Congratulations! You solved all problems.\n");
            break;
        }
        attempts++;
        printf("Incorrect answer or time ran out. Please try again.\n");
    }
    if(attempts == MAX_ATTEMPTS) {
        printf("Sorry! You could not solve all problems. Better luck next time.\n");
    }
    return 0;
}
//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, i, j, k, sum, count;
    double avg;
    struct data {
        int id;
        int age;
        char gender;
        int income;
    } dataset[100];

    printf("Enter the number of records: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("For record %d:\n", i+1);
        printf("Enter ID: ");
        scanf("%d", &dataset[i].id);
        printf("Enter age: ");
        scanf("%d", &dataset[i].age);
        printf("Enter gender (M/F): ");
        scanf(" %c", &dataset[i].gender);
        printf("Enter income: ");
        scanf("%d", &dataset[i].income);
    }

    printf("\nEnter the number of attributes to be mined: ");
    scanf("%d", &m);

    for(j=0; j<m; j++) {
        printf("Enter attribute %d:\n", j+1);
        scanf("%d", &k);
        sum = 0;
        count = 0;

        for(i=0; i<n; i++) {
            if(dataset[i].gender == 'M' && dataset[i].age >= 20 && dataset[i].age <= 30) {
                sum += dataset[i].income;
                count++;
            }
        }

        avg = (double)sum/count;
        printf("Average income of males aged 20-30: %.2lf\n", avg);
    }

    return 0;
}
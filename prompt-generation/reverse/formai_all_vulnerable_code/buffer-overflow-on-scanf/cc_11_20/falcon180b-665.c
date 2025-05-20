//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define N 10

int main() {
    int i, j, k, n, m, p, q, count = 0, flag = 0;
    int a[N], b[N], c[2*N];
    char ch;
    time_t start_time, end_time;
    double cpu_time_used;
    unsigned int rand_num;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n);

    printf("Enter the elements of the first array: ");
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &m);

    printf("Enter the elements of the second array: ");
    for(i=0; i<m; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the choice of operation:\n1. Bitwise AND\n2. Bitwise OR\n3. Bitwise XOR\n");
    scanf("%d", &ch);

    switch(ch) {
        case '1':
            for(i=0; i<n; i++) {
                for(j=0; j<m; j++) {
                    c[count] = a[i] & b[j];
                    count++;
                }
            }
            printf("Result of Bitwise AND operation:\n");
            for(i=0; i<count; i++) {
                printf("%d ", c[i]);
            }
            break;

        case '2':
            for(i=0; i<n; i++) {
                for(j=0; j<m; j++) {
                    c[count] = a[i] | b[j];
                    count++;
                }
            }
            printf("Result of Bitwise OR operation:\n");
            for(i=0; i<count; i++) {
                printf("%d ", c[i]);
            }
            break;

        case '3':
            for(i=0; i<n; i++) {
                for(j=0; j<m; j++) {
                    c[count] = a[i] ^ b[j];
                    count++;
                }
            }
            printf("Result of Bitwise XOR operation:\n");
            for(i=0; i<count; i++) {
                printf("%d ", c[i]);
            }
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}
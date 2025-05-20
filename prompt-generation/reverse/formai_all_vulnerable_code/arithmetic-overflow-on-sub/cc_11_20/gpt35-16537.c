//FormAI DATASET v1.0 Category: Educational ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    float student_marks[50];
    float mean, median, mode, variance, std_dev, sum = 0.0, sqr_sum = 0.0;
    int i, j, n;

    printf("Enter the number of students:\n");
    scanf("%d", &n);

    printf("Enter the marks of students:\n");

    for(i = 0; i < n; i++) {
        scanf("%f", &student_marks[i]);
        sum += student_marks[i];
    }

    mean = sum / n;

    for(i = 0; i < n; i++) {
        sqr_sum += pow(student_marks[i] - mean, 2);
    }

    variance = sqr_sum / n;
    std_dev = sqrt(variance);

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(student_marks[i] > student_marks[j]) {
                float temp = student_marks[i];
                student_marks[i] = student_marks[j];
                student_marks[j] = temp;
            }
        }
    }

    median = (n%2 == 0) ? (student_marks[n/2] + student_marks[(n/2)-1]) / 2 : student_marks[n/2];

    int max_count = 0, curr_count = 1;
    for(i = 1; i < n; i++) {
        if(student_marks[i] == student_marks[i-1]) {
            curr_count++;
        }
        else {
            if(curr_count > max_count) {
                max_count = curr_count;
                mode = student_marks[i-1];
            }
            curr_count = 1;
        }
    }
    if(curr_count > max_count) {
        mode = student_marks[n - 1];
    }

    printf("Mean = %.2f\n", mean);
    printf("Median = %.2f\n", median);
    printf("Mode = %.2f\n", mode);
    printf("Variance = %.2f\n", variance);
    printf("Standard Deviation = %.2f\n", std_dev);

    return 0;
}
//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: artistic
// Data Mining Example Program in Artistic Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store the data
struct data {
    int age;
    int income;
    int height;
    int weight;
    char gender;
    char education;
    char job;
};

// Function to read the data from a file
void read_data(struct data *d, int n, FILE *f) {
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d %d %d %d %c %c %c", &d[i].age, &d[i].income, &d[i].height, &d[i].weight, &d[i].gender, &d[i].education, &d[i].job);
    }
}

// Function to print the data
void print_data(struct data *d, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d %d %d %c %c %c\n", d[i].age, d[i].income, d[i].height, d[i].weight, d[i].gender, d[i].education, d[i].job);
    }
}

// Function to perform data mining
void data_mining(struct data *d, int n) {
    // Calculate the average income
    double sum_income = 0;
    for (int i = 0; i < n; i++) {
        sum_income += d[i].income;
    }
    double avg_income = sum_income / n;
    printf("Average income: %f\n", avg_income);

    // Calculate the average height
    double sum_height = 0;
    for (int i = 0; i < n; i++) {
        sum_height += d[i].height;
    }
    double avg_height = sum_height / n;
    printf("Average height: %f\n", avg_height);

    // Calculate the average weight
    double sum_weight = 0;
    for (int i = 0; i < n; i++) {
        sum_weight += d[i].weight;
    }
    double avg_weight = sum_weight / n;
    printf("Average weight: %f\n", avg_weight);

    // Calculate the percentage of male and female
    int male = 0;
    int female = 0;
    for (int i = 0; i < n; i++) {
        if (d[i].gender == 'M') {
            male++;
        } else {
            female++;
        }
    }
    double male_percentage = (double)male / n * 100;
    double female_percentage = (double)female / n * 100;
    printf("Percentage of male: %f%%\n", male_percentage);
    printf("Percentage of female: %f%%\n", female_percentage);

    // Calculate the percentage of high and low education
    int high = 0;
    int low = 0;
    for (int i = 0; i < n; i++) {
        if (d[i].education == 'H') {
            high++;
        } else {
            low++;
        }
    }
    double high_percentage = (double)high / n * 100;
    double low_percentage = (double)low / n * 100;
    printf("Percentage of high education: %f%%\n", high_percentage);
    printf("Percentage of low education: %f%%\n", low_percentage);

    // Calculate the percentage of different jobs
    int salesman = 0;
    int teacher = 0;
    int programmer = 0;
    for (int i = 0; i < n; i++) {
        if (d[i].job == 'S') {
            salesman++;
        } else if (d[i].job == 'T') {
            teacher++;
        } else {
            programmer++;
        }
    }
    double salesman_percentage = (double)salesman / n * 100;
    double teacher_percentage = (double)teacher / n * 100;
    double programmer_percentage = (double)programmer / n * 100;
    printf("Percentage of salesman: %f%%\n", salesman_percentage);
    printf("Percentage of teacher: %f%%\n", teacher_percentage);
    printf("Percentage of programmer: %f%%\n", programmer_percentage);
}

int main() {
    // Read the data from a file
    struct data d[10];
    int n = 10;
    FILE *f = fopen("data.txt", "r");
    read_data(d, n, f);

    // Perform data mining
    data_mining(d, n);

    // Print the data
    print_data(d, n);

    return 0;
}
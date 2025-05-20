//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold user data
struct user_data {
    char name[50];
    char email[50];
    char phone[50];
    int age;
    float salary;
    float expenses;
};

// Function to get user data
void get_user_data(struct user_data *data) {
    printf("Enter your name: ");
    scanf("%s", data->name);
    printf("Enter your email: ");
    scanf("%s", data->email);
    printf("Enter your phone number: ");
    scanf("%s", data->phone);
    printf("Enter your age: ");
    scanf("%d", &data->age);
    printf("Enter your salary: ");
    scanf("%f", &data->salary);
    printf("Enter your expenses: ");
    scanf("%f", &data->expenses);
}

// Function to calculate net salary
float calculate_net_salary(struct user_data *data) {
    return data->salary - data->expenses;
}

// Function to print financial planner
void print_financial_planner(struct user_data *data) {
    printf("Name: %s\n", data->name);
    printf("Email: %s\n", data->email);
    printf("Phone: %s\n", data->phone);
    printf("Age: %d\n", data->age);
    printf("Salary: %f\n", data->salary);
    printf("Expenses: %f\n", data->expenses);
    printf("Net Salary: %f\n", calculate_net_salary(data));
}

// Main function
int main() {
    // Create a new user data structure
    struct user_data user;

    // Get user data
    get_user_data(&user);

    // Print financial planner
    print_financial_planner(&user);

    return 0;
}
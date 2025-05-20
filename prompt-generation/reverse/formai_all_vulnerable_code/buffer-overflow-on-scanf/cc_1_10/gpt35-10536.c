//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

//Define struct for storing customer information
struct customer_info{
    char name[50];
    char address[100];
    char phone[20];
    int age;
    double salary;
};

//Function to print customer data
void print_customer_data(struct customer_info* customers, int num_customers){
    printf("\nCustomer Data:\n");
    for(int i=0; i<num_customers; i++){
        printf("Name: %s\n", customers[i].name);
        printf("Address: %s\n", customers[i].address);
        printf("Phone: %s\n", customers[i].phone);
        printf("Age: %d\n", customers[i].age);
        printf("Salary: %lf\n\n", customers[i].salary);
    }
}

//Function to find average salary of customers
double average_salary(struct customer_info* customers, int num_customers){
    double total_salary = 0;
    for(int i=0; i<num_customers; i++){
        total_salary += customers[i].salary;
    }
    return total_salary/num_customers;
}

int main(){
    //Get number of customers from user
    int num_customers;
    printf("How many customers do you want to enter data for? ");
    scanf("%d", &num_customers);
    
    //Allocate memory for customers struct based on number of customers
    struct customer_info* customers = (struct customer_info*) malloc(num_customers * sizeof(struct customer_info));
    
    //Prompt user to enter data for every customer
    for(int i=0; i<num_customers; i++){
        printf("\nEnter details of customer %d:\n", i+1);
        printf("Enter name: ");
        scanf("%s", customers[i].name);
        printf("Enter address: ");
        scanf("%s", customers[i].address);
        printf("Enter phone: ");
        scanf("%s", customers[i].phone);
        printf("Enter age: ");
        scanf("%d", &customers[i].age);
        printf("Enter salary: ");
        scanf("%lf", &customers[i].salary);
    }
    
    //Print customer data
    print_customer_data(customers, num_customers);
    
    //Find and print average salary of customers
    double avg_salary = average_salary(customers, num_customers);
    printf("Average Salary of Customers: %lf\n", avg_salary);
    
    //Free dynamically allocated memory
    free(customers);
    
    return 0;
}
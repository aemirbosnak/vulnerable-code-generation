//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[30];  
    char company[30];
    int mg;
    float price;
};

int main() {
    int choice, i, n;
    char search_name[30];
    struct medicine m[20];
    
    printf("\n---------MEDICAL STORE MANAGEMENT SYSTEM---------\n");
    
    while(1) {
        printf("\n1. Add Medicine\n");
        printf("2. Update Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Display All Medicine\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // To add medicine
                printf("\nEnter Number of Medicines to Add: ");
                scanf("%d", &n);
                
                for(i=0; i<n; i++) {
                    printf("\nMedicine %d Details: \n", i+1);
                    printf("Enter Medicine Name: ");
                    scanf("%s", m[i].name);
                    printf("Enter Medicine Company: ");
                    scanf("%s", m[i].company);
                    printf("Enter Medicine Strength (in mg): ");
                    scanf("%d", &m[i].mg);
                    printf("Enter Medicine Price: ");
                    scanf("%f", &m[i].price);
                }
                printf("\n%d Medicine Added Successfully!\n", n);
                break;
                
            case 2: // To update medicine
                printf("\nEnter Medicine Name to Update: ");
                scanf("%s", search_name);
                
                for(i=0; i<n; i++) {
                    if(strcmp(m[i].name, search_name) == 0) {
                        printf("\nMedicine %d Details: \n", i+1);
                        printf("Enter New Medicine Name: ");
                        scanf("%s", m[i].name);
                        printf("Enter New Medicine Company: ");
                        scanf("%s", m[i].company);
                        printf("Enter New Medicine Strength (in mg): ");
                        scanf("%d", &m[i].mg);
                        printf("Enter New Medicine Price: ");
                        scanf("%f", &m[i].price);
                        printf("\nMedicine Updated Successfully!\n");
                        break;
                    }
                }
                if(i == n) {
                    printf("\nMedicine Not Found!\n");
                }
                break;
                
            case 3: // To search medicine
                printf("\nEnter Medicine Name to Search: ");
                scanf("%s", search_name);
                
                for(i=0; i<n; i++) {
                    if(strcmp(m[i].name, search_name) == 0) {
                        printf("\nMedicine %d Details: \n", i+1);
                        printf("Medicine Name: %s\n", m[i].name);
                        printf("Medicine Company: %s\n", m[i].company);
                        printf("Medicine Strength (in mg): %d\n", m[i].mg);
                        printf("Medicine Price: %.2f\n", m[i].price);
                        break;
                    }
                }
                if(i == n) {
                    printf("\nMedicine Not Found!\n");
                }
                break;
                
            case 4: // To display all medicines
                if(n == 0) {
                    printf("\nNo Medicines Found!\n");
                    break;
                }
                printf("\n----------Available Medicines are----------\n");
                printf("Medicine Name\tCompany\tStrength (mg)\tPrice\n");
                
                for(i=0; i<n; i++) {
                    printf("%-15s %-15s %-15d %.2f\n", m[i].name, m[i].company, m[i].mg, m[i].price);
                }
                printf("\n");
                break;
                
            case 5: // To exit
                printf("\nTHANK YOU FOR USING THE MEDICAL STORE MANAGEMENT SYSTEM!\n");
                exit(0); // Terminating the program
                break;
                
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }
    return 0;
}
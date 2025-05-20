//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining structure for medical store
struct medicine{
    char name[50];
    int quantity;
    float price;
};

//Creating a function to add medicine
void addMedicine(struct medicine *m){
    printf("\nEnter name of medicine: ");
    scanf("%s",m->name);
    printf("Enter quantity of medicine: ");
    scanf("%d",&m->quantity);
    printf("Enter price of medicine: ");
    scanf("%f",&m->price);
}

//Creating a function to display all medicines
void displayMedicine(struct medicine m[]){
    int i,n;
    printf("\nName\tQuantity\tPrice\n");
    for(i=0;i<n;i++){
        printf("%s\t%d\t%.2f\n",m[i].name,m[i].quantity,m[i].price);
    }
}

int main(){
    int choice,n;
    struct medicine m[100];

    //Taking input for number of medicines
    printf("Enter number of medicines: ");
    scanf("%d",&n);

    //Looping through all medicines
    for(int i=0;i<n;i++){
        //Adding medicine
        addMedicine(&m[i]);
    }

    //Menu driven program
    do{
        printf("\n\nMENU\n");
        printf("1.Add Medicine\n");
        printf("2.Display Medicine\n");
        printf("3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                addMedicine(&m[n]);
                n++;
                break;

            case 2:
                displayMedicine(m);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }while(1);

    return 0;
}
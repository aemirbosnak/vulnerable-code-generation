//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct medicine{
    char name[30],company[30],expiry[10];
    int id,quantity;
    float cost;
};

int main(){
    int n, choice, id, i;
    struct medicine med;
    FILE *fp;
    
    while(1){
        printf("\n\n----------------------------------------\n");
        printf("      MEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("----------------------------------------\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicine\n");
        printf("3. Delete Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Exit\n");
        printf("----------------------------------------\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: //Add Medicine
                fp = fopen("medicines.txt", "a");
                printf("\nEnter the id of medicine: ");
                scanf("%d", &med.id);
                printf("Enter the name of medicine: ");
                scanf("%s", med.name);
                printf("Enter the name of company: ");
                scanf("%s", med.company);
                printf("Enter the expiry date (dd/mm/yyyy): ");
                scanf("%s", med.expiry);
                printf("Enter the quantity: ");
                scanf("%d", &med.quantity);
                printf("Enter the cost per unit: ");
                scanf("%f", &med.cost);
                fwrite(&med, sizeof(struct medicine), 1, fp);
                fclose(fp);
                printf("\nMedicine added successfully!");
                break;
                
            case 2: //View Medicine
                fp = fopen("medicines.txt", "r");
                if(fp == NULL){
                    printf("No medicines available!");
                    break;
                }
                printf("\n------- MEDICINES AVAILABLE -------\n");
                printf("\nID\tNAME\tCOMPANY\tEXPIRY\tQUANTITY\tCOST/UNIT");
                while(fread(&med, sizeof(struct medicine), 1, fp)){
                    printf("\n%d\t", med.id);
                    printf("%s\t", med.name);
                    printf("%s\t", med.company);
                    printf("%s\t", med.expiry);
                    printf("%d\t\t", med.quantity);
                    printf("%.2f", med.cost);
                }
                fclose(fp);
                break;
                
            case 3: //Delete Medicine
                printf("\nEnter the id of medicine to delete: ");
                scanf("%d", &id);
                fp = fopen("medicines.txt", "r");
                FILE *fp1;
                fp1 = fopen("temp.txt", "w");
                i = 0;
                while(fread(&med, sizeof(struct medicine), 1, fp)){
                    if(med.id != id){
                        fwrite(&med, sizeof(struct medicine), 1, fp1);
                        i++;
                    }
                }
                fclose(fp);
                fclose(fp1);
                remove("medicines.txt");
                rename("temp.txt", "medicines.txt");
                if(i != 0){
                    printf("\nMedicine deleted successfully!");
                }else{
                    printf("\nMedicine not found!");
                }
                break;
                
            case 4: //Update Medicine
                printf("\nEnter the id of medicine to update: ");
                scanf("%d", &id);
                fp = fopen("medicines.txt", "r");
                FILE *fp2;
                fp2 = fopen("temp.txt", "w");
                i = 0;
                while(fread(&med, sizeof(struct medicine), 1, fp)){
                    if(med.id == id){
                        printf("Enter the name of medicine: ");
                        scanf("%s", med.name);
                        printf("Enter the name of company: ");
                        scanf("%s", med.company);
                        printf("Enter the expiry date (dd/mm/yyyy): ");
                        scanf("%s", med.expiry);
                        printf("Enter the quantity: ");
                        scanf("%d", &med.quantity);
                        printf("Enter the cost per unit: ");
                        scanf("%f", &med.cost);
                    }
                    fwrite(&med, sizeof(struct medicine), 1, fp2);
                    i++;
                }
                fclose(fp);
                fclose(fp2);
                remove("medicines.txt");
                rename("temp.txt", "medicines.txt");
                if(i != 0){
                    printf("\nMedicine updated successfully!");
                }else{
                    printf("\nMedicine not found!");
                }
                break;
                
            case 5: //Exit
                printf("\nThank you for using the program!\n");
                exit(0);
                break;
                
            default:
                printf("\nInvalid choice!\n");
        }
    }
    
    return 0;
}
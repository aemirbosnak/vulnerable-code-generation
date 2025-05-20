//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicines{
    int med_id;
    char med_name[50];
    float med_price;
};

void add_medicine(struct medicines[], int*);
void display_all_medicine(struct medicines[], int);
void search_medicine(struct medicines[], int);
void update_medicine(struct medicines[], int);
void delete_medicine(struct medicines[], int*);

int main(){
    int option, med_count = 0, max_meds = 100;
    struct medicines medicine[max_meds];

    do{
        printf("\n\n------ MEDICAL STORE MANAGEMENT SYSTEM ------ \n\n");
        printf("Enter your choice: \n");
        printf("1. Add medicine details\n");
        printf("2. Display all medicine details\n");
        printf("3. Search medicine\n");
        printf("4. Update medicine details\n");
        printf("5. Delete medicine details\n");
        printf("0. Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option){
            case 0:
                printf("\nExiting the program...\n");
                break;

            case 1:
                add_medicine(medicine, &med_count);
                break;

            case 2:
                display_all_medicine(medicine, med_count);
                break;

            case 3:
                search_medicine(medicine, med_count);
                break;

            case 4:
                update_medicine(medicine, med_count);
                break;

            case 5:
                delete_medicine(medicine, &med_count);
                break;

            default:
                printf("Invalid option! Try again.\n");
        }
    }while(option != 0);

    return 0;
}

void add_medicine(struct medicines medicine[], int* med_count){
    printf("\n--- Add Medicine details ---\n");
    printf("Enter medicine ID: ");
    scanf("%d", &medicine[*med_count].med_id);
    printf("Enter medicine name: ");
    scanf("%s", medicine[*med_count].med_name);
    printf("Enter medicine price: ");
    scanf("%f", &medicine[*med_count].med_price);

    (*med_count)++;
}

void display_all_medicine(struct medicines medicine[], int med_count){
    if(med_count == 0)
        printf("\nNo medicines added yet!\n");
    else{
        printf("\n--- All Medicine details ---\n");
        printf("ID\t NAME\t PRICE\n");
        for(int i = 0; i < med_count; i++){
            printf("%d\t %s\t %.2f\n", medicine[i].med_id, medicine[i].med_name, medicine[i].med_price);
        }
    }
}

void search_medicine(struct medicines medicine[], int med_count){
    int med_id;

    if(med_count == 0)
        printf("\nNo medicines added yet!\n");
    else{
        printf("\n--- Search Medicine ---\n");
        printf("Enter medicine ID to search: ");
        scanf("%d", &med_id);
        
        for(int i = 0; i < med_count; i++){
            if(medicine[i].med_id == med_id){
                printf("ID\t NAME\t PRICE\n");
                printf("%d\t %s\t %.2f\n", medicine[i].med_id, medicine[i].med_name, medicine[i].med_price);
                return;
            }
        }
        printf("Medicine with ID %d not found!\n", med_id);
    }   
}

void update_medicine(struct medicines medicine[], int med_count){
    int med_id;

    if(med_count == 0)
        printf("\nNo medicines added yet!\n");
    else{
        printf("\n--- Update Medicine details ---\n");
        printf("Enter medicine ID to update: ");
        scanf("%d", &med_id);
        
        for(int i = 0; i < med_count; i++){
            if(medicine[i].med_id == med_id){
                printf("Enter updated medicine name: ");
                scanf("%s", medicine[i].med_name);
                printf("Enter updated medicine price: ");
                scanf("%f", &medicine[i].med_price);
                printf("Medicine details updated successfully!\n");
                return;
            }
        }
        printf("Medicine with ID %d not found!\n", med_id);
    }   
}

void delete_medicine(struct medicines medicine[], int* med_count){
    int med_id;

    if(*med_count == 0)
        printf("\nNo medicines added yet!\n");
    else{
        printf("\n--- Delete Medicine details ---\n");
        printf("Enter medicine ID to delete: ");
        scanf("%d", &med_id);

        for(int i = 0; i < *med_count; i++){
            if(medicine[i].med_id == med_id){
                for(int j = i; j < *med_count-1; j++){
                    medicine[j] = medicine[j+1];
                }
                (*med_count)--;
                printf("Medicine details deleted successfully!\n");
                return;
            }
        }
        printf("Medicine with ID %d not found!\n", med_id);
    }   
}
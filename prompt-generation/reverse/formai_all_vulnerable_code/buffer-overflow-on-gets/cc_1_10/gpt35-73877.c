//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shocked
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct guest{
    char name[30];
    char address[50];
    char contact[15];
    char gender[10];
    int age;
    char room_type[10];
    float room_cost;
    int duration;
    float total_cost;
};

void add_guest();
void view_guest();
void search_guest();
void edit_guest();
void delete_guest();

int main(){
    int choice;
    while(1){
        printf("HOTEL MANAGEMENT SYSTEM\n");
        printf("\n");
        printf("1. Add Guest\n");
        printf("2. View Guest\n");
        printf("3. Search Guest\n");
        printf("4. Edit Guest\n");
        printf("5. Delete Guest\n");
        printf("6. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: add_guest(); break;
            case 2: view_guest(); break;
            case 3: search_guest(); break;
            case 4: edit_guest(); break;
            case 5: delete_guest(); break;
            case 6: exit(0);
            default: printf("Invalid Choice\n"); break;
        }
    }
    return 0;
}

void add_guest(){
    FILE *fp;
    struct guest g;
    fp=fopen("guests.txt","a");

    printf("\n");
    printf("ADD GUEST\n");
    printf("Enter name: ");
    fflush(stdin);
    gets(g.name);
    printf("Enter address: ");
    fflush(stdin);
    gets(g.address);
    printf("Enter contact number: ");
    fflush(stdin);
    gets(g.contact);
    printf("Enter gender: ");
    fflush(stdin);
    gets(g.gender);
    printf("Enter age: ");
    scanf("%d", &g.age);
    printf("Enter room type: ");
    fflush(stdin);
    gets(g.room_type);
    printf("Enter room cost: ");
    scanf("%f", &g.room_cost);
    printf("Enter duration of stay(in days): ");
    scanf("%d", &g.duration);
    g.total_cost = g.duration * g.room_cost;

    fwrite(&g,sizeof(g),1,fp);

    printf("\nSuccessfully added guest\n");

    fclose(fp);

}

void view_guest(){
    FILE *fp;
    struct guest g;
    fp=fopen("guests.txt","r");

    printf("\n");
    printf("VIEW GUEST\n");
    printf("\n");
    printf("Name\tAddress\tContact\tGender\tAge\tRoom Type\tRoom Cost\tDuration\tTotal Cost\n");

    while(fread(&g,sizeof(g),1,fp)){
        printf("%s\t%s\t%s\t%s\t%d\t%s\t\t%.2f\t\t%d\t\t%.2f\n", g.name, g.address, g.contact, g.gender, g.age, g.room_type, g.room_cost, g.duration, g.total_cost);
    }

    fclose(fp);
}

void search_guest(){
    FILE *fp;
    struct guest g;
    char name[30], contact[15];
    fp=fopen("guests.txt","r");

    printf("\n");
    printf("SEARCH GUEST\n");
    printf("\n");
    printf("Enter name or contact number of guest to search: ");
    fflush(stdin);
    gets(name);

    while(fread(&g,sizeof(g),1,fp)){
        if(strcmp(name,g.name)==0 || strcmp(name,g.contact)==0){
            printf("\n");
            printf("Name\tAddress\tContact\tGender\tAge\tRoom Type\tRoom Cost\tDuration\tTotal Cost\n");
            printf("%s\t%s\t%s\t%s\t%d\t%s\t\t%.2f\t\t%d\t\t%.2f\n", g.name, g.address, g.contact, g.gender, g.age, g.room_type, g.room_cost, g.duration, g.total_cost);
            fclose(fp);
            return;
        }
    }

    printf("\nGuest not found\n");
    fclose(fp);
}

void edit_guest(){
    FILE *fp, *fp_tmp;
    struct guest g;
    char name[30];
    int found = 0;
    fp=fopen("guests.txt","r");
    fp_tmp=fopen("temp.txt","w");

    printf("\n");
    printf("EDIT GUEST\n");
    printf("\n");
    printf("Enter name of guest to edit: ");
    fflush(stdin);
    gets(name);

    while(fread(&g,sizeof(g),1,fp)){
        if(strcmp(name,g.name)==0){
            found = 1;
            printf("\nOld data\n");
            printf("Name\tAddress\tContact\tGender\tAge\tRoom Type\tRoom Cost\tDuration\tTotal Cost\n");
            printf("%s\t%s\t%s\t%s\t%d\t%s\t\t%.2f\t\t%d\t\t%.2f\n", g.name, g.address, g.contact, g.gender, g.age, g.room_type, g.room_cost, g.duration, g.total_cost);

            printf("\nEnter new data\n");
            printf("Enter name: ");
            fflush(stdin);
            gets(g.name);
            printf("Enter address: ");
            fflush(stdin);
            gets(g.address);
            printf("Enter contact number: ");
            fflush(stdin);
            gets(g.contact);
            printf("Enter gender: ");
            fflush(stdin);
            gets(g.gender);
            printf("Enter age: ");
            scanf("%d", &g.age);
            printf("Enter room type: ");
            fflush(stdin);
            gets(g.room_type);
            printf("Enter room cost: ");
            scanf("%f", &g.room_cost);
            printf("Enter duration of stay(in days): ");
            scanf("%d", &g.duration);
            g.total_cost = g.duration * g.room_cost;

            fwrite(&g,sizeof(g),1,fp_tmp);

            printf("\nSuccessfully edited guest\n");
        }
        else{
            fwrite(&g,sizeof(g),1,fp_tmp);
        }
    }

    fclose(fp);
    fclose(fp_tmp);

    if(found==0){
        printf("\nGuest not found\n");
        remove("temp.txt");
    }
    else{
        remove("guests.txt");
        rename("temp.txt","guests.txt");
    }
}

void delete_guest(){
    FILE *fp, *fp_tmp;
    struct guest g;
    char name[30];
    int found = 0;
    fp=fopen("guests.txt","r");
    fp_tmp=fopen("temp.txt","w");

    printf("\n");
    printf("DELETE GUEST\n");
    printf("\n");
    printf("Enter name of guest to delete: ");
    fflush(stdin);
    gets(name);

    while(fread(&g,sizeof(g),1,fp)){
        if(strcmp(name,g.name)==0){
            found = 1;
            printf("\nSuccessfully deleted guest\n");
            printf("Name\tAddress\tContact\tGender\tAge\tRoom Type\tRoom Cost\tDuration\tTotal Cost\n");
            printf("%s\t%s\t%s\t%s\t%d\t%s\t\t%.2f\t\t%d\t\t%.2f\n", g.name, g.address, g.contact, g.gender, g.age, g.room_type, g.room_cost, g.duration, g.total_cost);
        }
        else{
            fwrite(&g,sizeof(g),1,fp_tmp);
        }
    }

    fclose(fp);
    fclose(fp_tmp);

    if(found==0){
        printf("\nGuest not found\n");
        remove("temp.txt");
    }
    else{
        remove("guests.txt");
        rename("temp.txt","guests.txt");
    }
}
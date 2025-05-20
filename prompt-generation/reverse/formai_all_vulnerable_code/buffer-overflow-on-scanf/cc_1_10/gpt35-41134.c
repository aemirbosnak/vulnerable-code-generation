//FormAI DATASET v1.0 Category: File handling ; Style: medieval
#include<stdio.h>
#include<string.h>

struct Knight{
    char name[20];
    int age;
    char rank[20];
    int battles_won;
};

void add_knight(){
    struct Knight k;
    printf("\nEnter Knight's Name: ");
    scanf("%s", &k.name);
    printf("Enter Knight's Age: ");
    scanf("%d", &k.age);
    printf("Enter Knight's Rank: ");
    scanf("%s", &k.rank);
    printf("Enter Number of Battles Won: ");
    scanf("%d", &k.battles_won);
    
    FILE *fp;
    fp = fopen("medieval_knights.txt", "a");
    fprintf(fp, "%s %d %s %d\n", k.name, k.age, k.rank, k.battles_won);
    fclose(fp);
    printf("\nKnight added successfully to the record.\n");
}

void display_records(){
    FILE *fp;
    fp = fopen("medieval_knights.txt", "r");
    printf("\nKnights in the Record:\n\n");
    printf("%-20s %-5s %-10s %-15s\n", "Name", "Age", "Rank", "Battles Won");
    printf("--------------------------------------------------------\n");
    
    struct Knight k;
    while(fscanf(fp, "%s %d %s %d", k.name, &k.age, k.rank, &k.battles_won) != EOF){
        printf("%-20s %-5d %-10s %-15d\n", k.name, k.age, k.rank, k.battles_won);
    }
    
    fclose(fp);
}

void search_knights(){
    FILE *fp;
    fp = fopen("medieval_knights.txt", "r");
    char name[20];
    printf("Enter the name of the knight to search: ");
    scanf("%s", &name);
    
    struct Knight k;
    int found=0;
    while(fscanf(fp, "%s %d %s %d", k.name, &k.age, k.rank, &k.battles_won) != EOF){
        if(strcmp(name,k.name) == 0){
            printf("\n%-20s %-5s %-10s %-15s\n", "Name", "Age", "Rank", "Battles Won");
            printf("--------------------------------------------------------\n");
            printf("%-20s %-5d %-10s %-15d\n", k.name, k.age, k.rank, k.battles_won);
            found = 1;
        }
    }
    fclose(fp);
    if(found == 0)
        printf("\nKnight not found in the record.\n");
}

void update_knight(){
    FILE *fp;
    fp = fopen("medieval_knights.txt", "r+");
    char name[20];
    printf("Enter the name of the knight to update: ");
    scanf("%s", &name);
    
    struct Knight k;
    int found=0;
    while(fscanf(fp, "%s %d %s %d", k.name, &k.age, k.rank, &k.battles_won) != EOF){
        if(strcmp(name,k.name) == 0){
            printf("\nEnter new Age for the Knight: ");
            scanf("%d", &k.age);
            printf("Enter new Rank for the Knight: ");
            scanf("%s", &k.rank);
            printf("Enter new number of Battles Won for the Knight: ");
            scanf("%d", &k.battles_won);
            fseek(fp, -sizeof(k), SEEK_CUR);
            fprintf(fp, "%s %d %s %d", k.name, k.age, k.rank, k.battles_won);
            printf("\nKnight record updated successfully.\n");
            found=1;
            break;
        }
    }
    fclose(fp);
    if(found == 0)
        printf("\nKnight not found in the record.\n");
}

void delete_knight(){
    FILE *fp;
    fp = fopen("medieval_knights.txt", "r+");
    char name[20];
    printf("Enter the name of the knight to delete: ");
    scanf("%s", &name);
    
    FILE *temp;
    temp = fopen("medieval_knights_temp.txt", "w");
    
    struct Knight k;
    int found=0;
    while(fscanf(fp, "%s %d %s %d", k.name, &k.age, k.rank, &k.battles_won) != EOF){
        if(strcmp(name,k.name) != 0){
            fprintf(temp, "%s %d %s %d\n", k.name, k.age, k.rank, k.battles_won);
        }else{
            printf("\nKnight record deleted successfully.\n");
            found=1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("medieval_knights.txt");
    rename("medieval_knights_temp.txt", "medieval_knights.txt");
    if(found == 0)
        printf("\nKnight not found in the record.\n");
}

int main(){
    int choice;
    printf("Welcome to the Medieval Knights' Record System!\n");
    printf("------------------------------------------------\n");
    while(1){
        printf("\nWhat do you want to do?\n");
        printf("1. Add a Knight.\n");
        printf("2. Display all Knights.\n");
        printf("3. Search for a Knight.\n");
        printf("4. Update a Knight's Record.\n");
        printf("5. Delete a Knight's Record.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                add_knight();
                break;
            case 2:
                display_records();
                break;
            case 3:
                search_knights();
                break;
            case 4:
                update_knight();
                break;
            case 5:
                delete_knight();
                break;
            case 6:
                printf("\nExiting the Record System.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
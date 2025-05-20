//FormAI DATASET v1.0 Category: Online Examination System ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[50];
    int roll;
    float marks;
};

void showMenu(){
    printf("\n");
    printf("C Online Examination System\n");
    printf("1. View Results\n");
    printf("2. Add Results\n");
    printf("3. Edit Results\n");
    printf("4. Delete Results\n");
    printf("5. Exit\n");
    printf("Enter Your Choice: ");
}

void viewResults(){
    FILE *fp;
    struct student st;
    fp = fopen("results.dat","rb");

    printf("\n");
    printf("Name\t\tRoll\t\tMarks\n");
    while(fread(&st,sizeof(struct student),1,fp)){
        printf("%-14s%-10d%6.2f\n",st.name,st.roll,st.marks);
    }

    fclose(fp);
}

void addResults(){
    FILE *fp;
    struct student st;
    fp = fopen("results.dat","ab");

    printf("\nEnter Student Name: ");
    scanf("%s",st.name);
    printf("Enter Roll Number: ");
    scanf("%d",&st.roll);
    printf("Enter Marks: ");
    scanf("%f",&st.marks);

    fwrite(&st,sizeof(struct student),1,fp);
    printf("\nAdded Successfully!\n");

    fclose(fp);

}

void editResults(){
    FILE *fp;
    int rno, found=0;
    struct student st;
    fp = fopen("results.dat","rb+");

    printf("\nEnter Roll Number to Edit: ");
    scanf("%d",&rno);

    while(fread(&st,sizeof(struct student),1,fp)){
        if(st.roll == rno){
            found = 1;
            printf("\nEnter New Name: ");
            scanf("%s",st.name);
            printf("Enter New Marks: ");
            scanf("%f",&st.marks);

            fseek(fp,-sizeof(struct student),SEEK_CUR);
            fwrite(&st,sizeof(struct student),1,fp);

            printf("\nEdited Successfull!\n");
            break;
        }
    }

    if(!found){
        printf("\nRecord not Found!\n");
    }

    fclose(fp);

}

void deleteResults(){
    FILE *fp, *temp;
    int rno, found=0;
    struct student st;
    fp = fopen("results.dat","rb");
    temp = fopen("temp.dat","wb");

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d",&rno);

    while(fread(&st,sizeof(struct student),1,fp)){
        if(st.roll != rno){
            fwrite(&st,sizeof(struct student),1,temp);
        }else{
            found = 1;
        }
    }

    if(!found){
        printf("\nRecord not Found!\n");
    }else{
        printf("\nDeleted Successfully!\n");
    }

    fclose(fp);
    fclose(temp);
    remove("results.dat");
    rename("temp.dat","results.dat");

}

int main(){

    int choice;

    while(1){
        showMenu();
        scanf("%d",&choice);

        switch(choice){
            case 1:
                viewResults();
                break;
            case 2:
                addResults();
                break;
            case 3:
                editResults();
                break;
            case 4:
                deleteResults();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid Option!\n");
        }
    }

    return 0;
}
//Falcon-180B DATASET v1.0 Category: File handling ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining the structure of the student
struct student{
    char name[50];
    int age;
    float cgpa;
};

//Function to read data from file
void read_data(struct student *s){
    FILE *fp;
    fp=fopen("data.txt","r");
    if(fp==NULL){
        printf("Error in opening file");
        exit(0);
    }
    while(!feof(fp)){
        fscanf(fp,"%s %d %f",s->name,&s->age,&s->cgpa);
        s++;
    }
    fclose(fp);
}

//Function to write data to file
void write_data(struct student *s){
    FILE *fp;
    fp=fopen("data.txt","w");
    if(fp==NULL){
        printf("Error in opening file");
        exit(0);
    }
    while(s->name[0]!='\0'){
        fprintf(fp,"%s %d %f\n",s->name,s->age,s->cgpa);
        s++;
    }
    fclose(fp);
}

//Function to search for a student
struct student *search_student(struct student *s,char *name){
    while(s->name[0]!='\0'){
        if(strcmp(s->name,name)==0){
            return s;
        }
        s++;
    }
    return NULL;
}

//Main function
int main(){
    struct student *s=NULL;
    s=(struct student *)malloc(sizeof(struct student));
    if(s==NULL){
        printf("Memory not allocated");
        exit(0);
    }
    //Reading data from file
    read_data(s);
    //Displaying the data
    printf("Name\tAge\tCGPA\n");
    while(s->name[0]!='\0'){
        printf("%s\t%d\t%.2f\n",s->name,s->age,s->cgpa);
        s++;
    }
    //Searching for a student
    s=search_student(s,"John");
    if(s!=NULL){
        printf("Student found\n");
    }
    else{
        printf("Student not found\n");
    }
    //Writing data to file
    write_data(s);
    return 0;
}
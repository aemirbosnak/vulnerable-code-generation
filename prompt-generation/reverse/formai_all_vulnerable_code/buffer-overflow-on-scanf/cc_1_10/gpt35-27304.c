//FormAI DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to hold the information of the indexed record
struct Record {
  char name[25];
  int id;
  float salary;
};

//Structure to hold the information of an index node
struct Node {
  int index;
  struct Node *next;
};

//Structure to hold the information of the index header
struct Index {
  char index_key[25];
  struct Node *head;
};

//Function to insert a new record in the database
void insertRecord(struct Record *database, int n, char *name, int id, float salary) {
  strcpy(database[n].name,name);
  database[n].id=id;
  database[n].salary=salary;
}

//Function to insert a new index node in the index list
void insertIndex(struct Index *index_header, int index) {
  struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
  new_node->index=index;
  new_node->next=NULL;
  if(index_header->head==NULL) {
    index_header->head=new_node;
  }
  else {
    struct Node *temp = index_header->head;
    while(temp->next!=NULL) {
      temp=temp->next;
    }
    temp->next=new_node;
  }
}

//Function to create the index for the database
void createIndex(struct Record *database, int n, struct Index *index_list, char *index_key) {
  int i, index;
  for(i=0;i<n;i++) {
    if(strcmp(index_key,"name")==0) {
      index = (int) database[i].name[0]+(int) database[i].name[1]+(int) database[i].name[2];
    }
    else if(strcmp(index_key,"id")==0) {
      index = database[i].id;
    }
    else if(strcmp(index_key,"salary")==0) {
      index = (int) database[i].salary/1000;
    }
    insertIndex(&index_list[index],i);
  }
}

//Function to print the records based on the index
void printIndex(struct Record *database, struct Index *index_list, char *index_key, int n) {
  int i, index;
  if(strcmp(index_key,"name")==0) {
    for(i=0;i<26;i++) {
      printf("Index %c:\n",'A'+i);
      struct Node *temp = index_list[i].head;
      while(temp!=NULL) {
        printf("%d %s %.2f\n",database[temp->index].id,database[temp->index].name,database[temp->index].salary);
        temp=temp->next;
      }
    }
  }
  else if(strcmp(index_key,"id")==0) {
    for(i=0;i<100;i++) {
      printf("Index %d:\n",i);
      struct Node *temp = index_list[i].head;
      while(temp!=NULL) {
        printf("%s %s %.2f\n",database[temp->index].name,database[temp->index].id,database[temp->index].salary);
        temp=temp->next;
      }
    }
  }
  else if(strcmp(index_key,"salary")==0) {
    for(i=0;i<11;i++) {
      printf("Index %d:\n",i*1000);
      struct Node *temp = index_list[i].head;
      while(temp!=NULL) {
        printf("%s %d %.2f\n",database[temp->index].name,database[temp->index].id,database[temp->index].salary);
        temp=temp->next;
      }
    }
  }
}

//Main function
int main() {
  int n, i, id, option;
  char name[25], index_key[25];
  float salary;
  
  printf("Enter the number of records in the database: ");
  scanf("%d",&n);
  
  struct Record *database = (struct Record*) malloc(n*sizeof(struct Record));
  
  printf("Enter the records in the format: <name> <id> <salary>\n");
  
  for(i=0;i<n;i++) {
    scanf("%s %d %f",name,&id,&salary);
    insertRecord(database,i,name,id,salary);
  }
  
  printf("Enter the index key (name/id/salary): ");
  scanf("%s",index_key);
  
  struct Index index_list[1000];
  for(i=0;i<1000;i++) {
    strcpy(index_list[i].index_key,index_key);
    index_list[i].head=NULL;
  }
  
  createIndex(database,n,index_list,index_key);
  
  printf("Records added successfully!\n");
  
  while(1) {
    printf("Enter the option (1-Print records/2-Exit): ");
    scanf("%d",&option);
    
    if(option==1) {
      printIndex(database,index_list,index_key,n);
    }
    else if(option==2) {
      printf("Exiting the program...\n");
      break;
    }
    else {
      printf("Invalid option\n");
    }
  }
  
  free(database);
  return 0;
}
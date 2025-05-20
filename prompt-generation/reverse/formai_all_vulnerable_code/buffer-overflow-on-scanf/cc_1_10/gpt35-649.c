//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include<stdio.h>
#include<string.h>

struct resume{
  char name[100];
  char education[100];
  char skills[100][100];
};

void parse(char *file_name){
  FILE *fp;
  fp = fopen(file_name, "r");
  if(fp==NULL){
    printf("File not found!");
    return;
  }
  
  char buffer[1024];
  size_t len = 0;
  ssize_t read;
  
  struct resume r;
  
  while ((read = getline(&buffer, &len, fp)) != -1) {
    if(strstr(buffer, "Name:")){
      strcpy(r.name, buffer+5);
      r.name[strlen(r.name)-1] = '\0';     
    }
    else if(strstr(buffer, "Education:")){
      strcpy(r.education, buffer+10);
      r.education[strlen(r.education)-1] = '\0';
    }
    else if(strstr(buffer, "Skills:")){
      int i = 0;
      char *token = strtok(buffer+7, ", ");
      while(token != NULL){
        strcpy(r.skills[i], token);
        token = strtok(NULL, ", ");
        i++;
      }      
    }
  }
  
  printf("Name: %s\n", r.name);
  printf("Education: %s\n", r.education);
  printf("Skills: ");
  for(int i=0; strlen(r.skills[i]); i++){
    printf("%s", r.skills[i]);
    if(strlen(r.skills[i+1])) printf(", ");
  }
  printf("\n");
  
  fclose(fp);
  return;  
}

int main(){
  printf("Enter resume file name:\n");
  char file_name[100];
  scanf("%s", file_name);
  
  parse(file_name);  
  
  return 0;
}
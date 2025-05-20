//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

struct Resume{
  char name[MAX_LENGTH];
  char address[MAX_LENGTH];
  char email[MAX_LENGTH];
  char phone[MAX_LENGTH];
  char education[MAX_LENGTH];
  char experience[MAX_LENGTH];
};

void parseResume(char *filename, struct Resume *res){
  FILE *fp;
  char buffer[MAX_LENGTH];

  if((fp=fopen(filename, "r")) == NULL){
    printf("Error opening file.\n");
    exit(1);
  }

  while(!feof(fp)){
    fscanf(fp, "%s", buffer);

    if(strstr(buffer, "Name")){
      fgets(res->name, MAX_LENGTH, fp);
    }
    else if(strstr(buffer, "Address")){
      fgets(res->address, MAX_LENGTH, fp);
    }
    else if(strstr(buffer, "Email")){
      fgets(res->email, MAX_LENGTH, fp);
    }
    else if(strstr(buffer, "Phone")){
      fgets(res->phone, MAX_LENGTH, fp);
    }
    else if(strstr(buffer, "Education")){
      fgets(res->education, MAX_LENGTH, fp);
    }
    else if(strstr(buffer, "Experience")){
      fgets(res->experience, MAX_LENGTH, fp);
    }
  }

  fclose(fp);
}

int main(){

  struct Resume res;
  char *filename = "resume.txt";

  parseResume(filename, &res);

  printf("Name: %s", res.name);
  printf("Address: %s", res.address);
  printf("Email: %s", res.email);
  printf("Phone: %s", res.phone);
  printf("Education: %s", res.education);
  printf("Experience: %s", res.experience);

  return 0;
}
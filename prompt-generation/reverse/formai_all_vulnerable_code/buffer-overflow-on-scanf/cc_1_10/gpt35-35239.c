//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume{
  char name[50];
  char email[50];
  char phone[15];
  char university[50];
  char degree[50];
  char skills[200];
  char experience[500];
} r;

int parse_resume(FILE *fp, struct resume *r);

int main()
{
  FILE *fp;
  char filename[50];
  struct resume r;

  printf("Enter file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  if(fp == NULL)
  {
    printf("File not found\n");
    return 0;
  }

  if(parse_resume(fp, &r) == 0)
  {
    printf("Error parsing resume\n");
    return 0;
  }

  printf("Name: %s\n", r.name);
  printf("Email: %s\n", r.email);
  printf("Phone: %s\n", r.phone);
  printf("University: %s\n", r.university);
  printf("Degree: %s\n", r.degree);
  printf("Skills: %s\n", r.skills);
  printf("Experience: %s\n", r.experience);

  fclose(fp);
  return 0;
}

int parse_resume(FILE *fp, struct resume *r)
{
  char line[100];

  while(fgets(line, 100, fp) != NULL)
  {
    if(strstr(line, "Name:") != NULL)
      strcpy(r->name, line+6);

    if(strstr(line, "Email:") != NULL)
      strcpy(r->email, line+7);

    if(strstr(line, "Phone:") != NULL)
      strcpy(r->phone, line+7);

    if(strstr(line, "University:") != NULL)
      strcpy(r->university, line+12);

    if(strstr(line, "Degree:") != NULL)
      strcpy(r->degree, line+8);

    if(strstr(line, "Skills:") != NULL)
      strcpy(r->skills, line+8);

    if(strstr(line, "Experience:") != NULL)
      strcpy(r->experience, line+12);
  }

  return 1;
}
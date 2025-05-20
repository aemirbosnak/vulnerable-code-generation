//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *address;
  char *skills;
  char *experience;
  char *education;
} resume;

int main() {
  resume r;
  char buf[1024];

  printf("Enter your name: ");
  scanf("%s", buf);
  r.name = strdup(buf);

  printf("Enter your email address: ");
  scanf("%s", buf);
  r.email = strdup(buf);

  printf("Enter your phone number: ");
  scanf("%s", buf);
  r.phone = strdup(buf);

  printf("Enter your address: ");
  scanf("%s", buf);
  r.address = strdup(buf);

  printf("Enter your skills: ");
  scanf("%s", buf);
  r.skills = strdup(buf);

  printf("Enter your experience: ");
  scanf("%s", buf);
  r.experience = strdup(buf);

  printf("Enter your education: ");
  scanf("%s", buf);
  r.education = strdup(buf);

  printf("\nYour resume:\n\n");
  printf("Name: %s\n", r.name);
  printf("Email: %s\n", r.email);
  printf("Phone: %s\n", r.phone);
  printf("Address: %s\n", r.address);
  printf("Skills: %s\n", r.skills);
  printf("Experience: %s\n", r.experience);
  printf("Education: %s\n", r.education);

  free(r.name);
  free(r.email);
  free(r.phone);
  free(r.address);
  free(r.skills);
  free(r.experience);
  free(r.education);

  return 0;
}
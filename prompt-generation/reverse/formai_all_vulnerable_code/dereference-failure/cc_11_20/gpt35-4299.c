//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* resume = 
"John Doe\n"
"123 Main Street\n"
"Anytown, USA 12345\n"
"(555) 555-5555\n"
"johndoe@email.com\n"
"\n"
"Objective: To obtain a challenging position in a dynamic organization that \n"
"offers opportunities for growth and development.\n"
"\n"
"Education: \n"
"BS in Computer Science, XYZ University, May 2020\n"
"GPA: 3.8/4.0\n"
"\n"
"Skills: \n"
"C++, Java, Python, MATLAB, MySQL, Linux, Agile Development, Scrum, Git\n"
"\n"
"Experience: \n"
"Software Engineer, ABC Company, June 2020 - Present\n"
"- Developed and maintained software applications using C++ and Java\n"
"- Collaborated with cross-functional teams to build scalable software solutions\n"
"- Participated in Agile development using Scrum and Git\n"
"\n"
"Software Developer Intern, XYZ Inc., May 2019 - August 2019\n"
"- Worked on a team to develop a Python-based CMS for managing website content\n"
"- Contributed to the design and implementation of the CMS\n"
"- Gained experience with MySQL and Linux\n"
"\n"
"Projects: \n"
"- Built a Java-based chat application using sockets\n"
"- Developed a MATLAB-based simulation of a DC motor\n"
;

int main()
{
  char* name;
  char* address;
  char* phone;
  char* email;
  char* objective;
  char* education;
  char* skills;
  char* experience;
  char* projects;
  
  // Allocate memory for each string
  name = (char*)malloc(50 * sizeof(char));
  address = (char*)malloc(100 * sizeof(char));
  phone = (char*)malloc(15 * sizeof(char));
  email = (char*)malloc(50 * sizeof(char));
  objective = (char*)malloc(200 * sizeof(char));
  education = (char*)malloc(200 * sizeof(char));
  skills = (char*)malloc(200 * sizeof(char));
  experience = (char*)malloc(400 * sizeof(char));
  projects = (char*)malloc(200 * sizeof(char));
  
  // Initialize each string
  name[0] = '\0';
  address[0] = '\0';
  phone[0] = '\0';
  email[0] = '\0';
  objective[0] = '\0';
  education[0] = '\0';
  skills[0] = '\0';
  experience[0] = '\0';
  projects[0] = '\0';
 
  // Parse the resume
  char* section_start = resume;
  char* section_end = strstr(section_start, "\n\n");
  while (section_end != NULL)
  {
    // Extract the section header
    char* section_header = strtok(section_start, ":");
    section_start = section_start + strlen(section_header) + 2;
    
    // Extract the section content
    char* section_content = strtok(section_start, "\n");
    section_start = section_end + 2;
    
    // Store the section content in the appropriate variable
    if (strcmp(section_header, "Name") == 0)
    {
      strncpy(name, section_content, 50);
    }
    else if (strcmp(section_header, "Address") == 0)
    {
      strncpy(address, section_content, 100);
    }
    else if (strcmp(section_header, "Phone") == 0)
    {
      strncpy(phone, section_content, 15);
    }
    else if (strcmp(section_header, "Email") == 0)
    {
      strncpy(email, section_content, 50);
    }
    else if (strcmp(section_header, "Objective") ==0)
    {
      strncpy(objective, section_content, 200);
    }
    else if (strcmp(section_header, "Education") == 0)
    {
      strncpy(education, section_content, 200);
    }
    else if (strcmp(section_header, "Skills") == 0)
    {
      strncpy(skills, section_content, 200);
    }
    else if (strcmp(section_header, "Experience") == 0)
    {
      strncpy(experience, section_content, 400);
    }
    else if (strcmp(section_header, "Projects") == 0)
    {
      strncpy(projects, section_content, 200);
    }
    
    // Move to the next section
    section_start = section_end + 2;
    section_end = strstr(section_start, "\n\n");
  }
  
  // Print the parsed data
  printf("Name: %s\n", name);
  printf("Address: %s\n", address);
  printf("Phone: %s\n", phone);
  printf("Email: %s\n", email);
  printf("Objective: %s\n", objective);
  printf("Education: %s\n", education);
  printf("Skills: %s\n", skills);
  printf("Experience: %s\n", experience);
  printf("Projects: %s\n", projects);
  
  // Free memory
  free(name);
  free(address);
  free(phone);
  free(email);
  free(objective);
  free(education);
  free(skills);
  free(experience);
  free(projects);
  
  return 0;
}
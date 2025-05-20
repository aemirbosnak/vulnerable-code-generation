//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main()
{
    char filename[100];
    char virus1[] = "virus1"; // replace with the actual virus name
    char virus2[] = "virus2"; // replace with the actual virus name
    char virus3[] = "virus3"; // replace with the actual virus name
    
    printf("Enter filename: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    
    if(file == NULL)
    {
        printf("File not found.\n");
        return 0;
    }
    
    char filecontent[1000];
    
    fgets(filecontent, 1000, file);
    
    int has_virus = 0;
    
    if(strstr(filecontent, virus1) != NULL)
    {
        printf("Virus %s found.\n", virus1);
        has_virus = 1;
    }
    
    if(strstr(filecontent, virus2) != NULL)
    {
        printf("Virus %s found.\n", virus2);
        has_virus = 1;
    }
    
    if(strstr(filecontent, virus3) != NULL)
    {
        printf("Virus %s found.\n", virus3);
        has_virus = 1;
    }
    
    if(has_virus == 0)
    {
        printf("File is safe.\n");
    }
    
    fclose(file);
    
    return 0;
}
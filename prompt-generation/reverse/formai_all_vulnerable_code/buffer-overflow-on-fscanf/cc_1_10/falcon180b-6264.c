//Falcon-180B DATASET v1.0 Category: File handling ; Style: happy
#include<stdio.h>
#include<stdlib.h>

// Structure for student information
struct student
{
    int roll_no;
    char name[50];
    float marks;
};

// Function to read student information from file
void read_from_file(FILE* file, struct student* student)
{
    fscanf(file, "%d %s %f", &student->roll_no, student->name, &student->marks);
}

// Function to write student information to file
void write_to_file(FILE* file, struct student* student)
{
    fprintf(file, "%d %s %f\n", student->roll_no, student->name, student->marks);
}

// Function to sort students based on their marks
void sort_students(struct student* students, int num_students)
{
    for(int i=0; i<num_students-1; i++)
    {
        for(int j=i+1; j<num_students; j++)
        {
            if(students[i].marks < students[j].marks)
            {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Main function
int main()
{
    FILE* file;
    struct student students[100];
    int num_students = 0;

    // Open the input file
    file = fopen("students.txt", "r");
    if(file == NULL)
    {
        printf("Error opening input file\n");
        exit(1);
    }

    // Read students from input file
    while(fscanf(file, "%d %s %f", &students[num_students].roll_no, students[num_students].name, &students[num_students].marks)!= EOF)
    {
        num_students++;
    }

    // Sort students based on their marks
    sort_students(students, num_students);

    // Open the output file
    file = fopen("sorted_students.txt", "w");
    if(file == NULL)
    {
        printf("Error opening output file\n");
        exit(1);
    }

    // Write sorted students to output file
    for(int i=0; i<num_students; i++)
    {
        write_to_file(file, &students[i]);
    }

    // Close the input and output files
    fclose(file);
    fclose(file);

    return 0;
}
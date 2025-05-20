//FormAI DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LEN 50
#define MAX_QUERY_LEN 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int math_score;
    int physics_score;
} Student;

int main() {
    // Create a sample database
    Student students[] = {
        {1, "John Smith", 85, 75},
        {2, "Mary Jones", 90, 80},
        {3, "Bob Johnson", 70, 95},
        {4, "Samantha Lee", 95, 85},
        {5, "Mike Chen", 80, 90}
    };
    int num_students = sizeof(students) / sizeof(students[0]);
    
    // Prompt user for query
    char query[MAX_QUERY_LEN];
    printf("Enter query (e.g. 'math_score > 80 AND physics_score > 80'):\n");
    fgets(query, MAX_QUERY_LEN, stdin);
    
    // Parse query
    int num_conditions = 0;
    char* condition_tokens[10];
    char* token = strtok(query, " ");
    while (token != NULL) {
        if (strcmp(token, "AND") == 0) {
            num_conditions++;
        } else {
            condition_tokens[num_conditions] = token;
        }
        token = strtok(NULL, " ");
    }
    num_conditions++;
    
    // Construct SQL statement based on query conditions
    char sql_statement[MAX_QUERY_LEN*2];
    sprintf(sql_statement, "SELECT * FROM students WHERE ");
    for (int i = 0; i < num_conditions; i++) {
        char* condition = condition_tokens[i];
        char operator[3];
        int value;
        if (sscanf(condition, "math_score %2s %d", operator, &value) == 2) {
            strcat(sql_statement, "math_score ");
            strcat(sql_statement, operator);
            char value_str[10];
            sprintf(value_str, " %d AND ", value);
            strcat(sql_statement, value_str);
        } else if (sscanf(condition, "physics_score %2s %d", operator, &value) == 2) {
            strcat(sql_statement, "physics_score ");
            strcat(sql_statement, operator);
            char value_str[10];
            sprintf(value_str, " %d AND ", value);
            strcat(sql_statement, value_str);
        }
    }
    sql_statement[strlen(sql_statement)-5] = '\0';
    
    // Execute query on database
    printf("Executing query: %s\n", sql_statement);
    printf("Results:\n");
    printf("ID | Name          | Math Score | Physics Score\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < num_students; i++) {
        Student student = students[i];
        char this_statement[MAX_QUERY_LEN];
        sprintf(this_statement, "SELECT * FROM students WHERE id=%d AND %s", student.id, sql_statement+7);
        if (system(this_statement) == 0) {  // query returns non-zero value if a match is found
            printf("%-2d | %-12s | %2d         | %2d\n", student.id, student.name, student.math_score, student.physics_score);
        }
    }
    printf("----------------------------------------------\n");
    
    return 0;
}
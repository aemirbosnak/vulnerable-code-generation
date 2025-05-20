//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include <math.h>

// Shape structure definition
typedef struct {
    char name[20];
    float area;
} Shape;

// Function to calculate area based on shape type
float calculate_area(const char* shape_type, float dimension) {
    if (strcmp(shape_type, "circle") == 0) {
        return M_PI * dimension * dimension;
    } else if (strcmp(shape_type, "square") == 0) {
        return dimension * dimension;
    } else if (strcmp(shape_type, "triangle") == 0) {
        return (sqrt(3) / 4) * dimension * dimension; // Equilateral triangle
    }
    return -1.0; // Invalid shape
}

// SQLite callback function
static int callback(void *data, int argc, char **argv, char **azColName) {
    printf("%s: \n", (const char*)data);
    for (int i = 0; i < argc; i++) {
        printf(" %s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Function to execute a query
void execute_query(sqlite3 *db, const char *query) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    }
}

// Function to create table if it doesn’t exist
void create_table(sqlite3 *db) {
    const char *sql = "CREATE TABLE IF NOT EXISTS Shapes(Name TEXT, Area REAL);";
    execute_query(db, sql);
}

// Function to insert shape into database
void insert_shape(sqlite3 *db, Shape *shape) {
    char sql[100];
    snprintf(sql, sizeof(sql), "INSERT INTO Shapes VALUES('%s', %f);", shape->name, shape->area);
    execute_query(db, sql);
}

// Function to query shapes by type
void query_shapes(sqlite3 *db, const char *shape_type) {
    char sql[100];
    snprintf(sql, sizeof(sql), "SELECT * FROM Shapes WHERE Name = '%s';", shape_type);
    execute_query(db, sql);
}

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("shapes.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    } 

    create_table(db);
    
    int option;
    do {
        printf("Shape Database Menu:\n");
        printf("1. Add a Shape\n");
        printf("2. Query Shapes\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        if (option == 1) {
            Shape shape;
            printf("Enter shape type (circle/square/triangle): ");
            scanf("%s", shape.name);
            float dimension;
            printf("Enter dimension (radius for circle, side for square/triangle): ");
            scanf("%f", &dimension);
            shape.area = calculate_area(shape.name, dimension);
            if (shape.area != -1) {
                insert_shape(db, &shape);
                printf("Inserted shape %s with area: %f\n", shape.name, shape.area);
            } else {
                printf("Invalid shape type!\n");
            }
        } else if (option == 2) {
            char shape_type[20];
            printf("Enter shape type to query: ");
            scanf("%s", shape_type);
            query_shapes(db, shape_type);
        }
        
    } while (option != 3);

    sqlite3_close(db);
    return 0;
}